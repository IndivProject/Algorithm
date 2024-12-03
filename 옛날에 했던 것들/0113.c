#include <stdio.h>

int main(){
    float minute = 0, minute_angle = 0, hour = 0, hour_angle = 0 ;
    int angle = 22,ch = 0,saveHour[10000] = {0,}, saveMinute[10000] = {0,};
    while (1)
    {
        minute += 1;
        minute_angle += 6;
        if(minute == 60){
            minute = 0;
            minute_angle = 0;
            hour += 1;
        }
        hour_angle += 0.5;
       //printf("%0.f %0.f %0.f %0.f \n",minute_angle-hour_angle, minute_angle + hour_angle, hour_angle - minute_angle, hour_angle+ minute_angle);
       //printf("tl:qns %0.f %0.f\n",hour, minute);
        if(hour == 13) break;
        if(((minute_angle - hour_angle) == angle || (hour_angle - minute_angle) == angle )||
        (360 - (minute_angle - hour_angle) == angle ||  360 - (hour_angle - minute_angle) == angle)){
            saveHour[ch] = (int)hour;
            saveMinute[ch] = (int)minute;
            ch++;
            printf("%02d:%02d\n\n", (int)hour, (int)minute);
        }
        // printf("%02d:%02d\n", (int)hour, (int)minute);
        //     printf("%0.f %0.f %0.f %0.f \n\n",minute_angle-hour_angle, minute_angle + hour_angle, hour_angle - minute_angle, hour_angle+ minute_angle);
    }
    printf("%d\n",ch);
    for(int i =0;i<ch;i++){
        printf("%02d:%02d\n", saveHour[i], saveMinute[i]);
    }
    return 0;
}