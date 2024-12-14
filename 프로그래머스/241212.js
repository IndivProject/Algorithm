const ChangeTime = (minutes, seconds) => {
  return Number(minutes) * 60 + Number(seconds);
};

const ChangeMinutes = (time) => {
  if ((time - (time % 60)) / 60 < 10) {
    if (time % 60 < 10) return `0${(time - (time % 60)) / 60}:0${time % 60}`;
    else return `0${(time - (time % 60)) / 60}:${time % 60}`;
  } else {
    if (time % 60 < 10) return `${(time - (time % 60)) / 60}:0${time % 60}`;
    else return `${(time - (time % 60)) / 60}:${time % 60}`;
  }
};

function solution(video_len, pos, op_start, op_end, commands) {
  let video = ChangeTime(video_len.split(":")[0], video_len.split(":")[1]);
  let position = ChangeTime(pos.split(":")[0], pos.split(":")[1]);
  let start = ChangeTime(op_start.split(":")[0], op_start.split(":")[1]);
  let end = ChangeTime(op_end.split(":")[0], op_end.split(":")[1]);

  for (let i = 0; i < commands.length; i++) {
    if (position >= start && position < end) position = end;
    switch (commands[i]) {
      case "next":
        position += 10;
        if (video < position) position = video;
        if (position >= start && position < end) position = end;
        break;
      case "prev":
        position -= 10;
        if (position < 0) position = 0;
        if (position >= start && position < end) position = end;
        break;
    }
  }

  // console.log(ChangeMinutes(position));

  return ChangeMinutes(position);
}
