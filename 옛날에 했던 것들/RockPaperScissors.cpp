#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int win = 0,lose = 0, ch = 0, flag = 0;
int random = 0;

//가위면 작동되는 코드
void one(int a) {
	if (random == a) {
		printf("나 : 가위 / 컴퓨터 : 가위\n");
		printf("\n컴퓨터랑 사겨라\n\n");
		printf("현재 점수 : %d / %d\n\n",win,lose);

	}
	else if (random == 2) {
		printf("나 : 가위 / 컴퓨터 : 바위\n");
		printf("\n이걸 지네\n\n");
		printf("현재 점수 : %d / %d\n\n", win, ++lose);
	}
	else if (random == 3) {
		printf("나 : 가위 / 컴퓨터 : 바위\n");
		printf("\n'이김'\n\n");
		printf("현재 점수 : %d / %d\n\n", ++win, lose);
	}
}

//바위면 작동되는 코드
void two(int a) {
	if (random == a) {
		printf("나 : 바위 / 컴퓨터 : 바위\n");
		printf("\n비겼습니다!\n\n");
		printf("현재 점수 : %d / %d\n\n", win, lose);

	}
	else if (random == 3) {
		printf("나 : 바위 / 컴퓨터 : 보\n");
		printf("\n컴퓨터한테 지네\n\n");
		printf("현재 점수 : %d / %d\n\n", win, ++lose);
	}
	else if (random == 1) {
		printf("나 : 바위 / 컴퓨터 : 가위\n");
		printf("\n남자는 바위지\n\n");
		printf("현재 점수 : %d / %d\n\n", ++win, lose);
	}
}

//보면 작동되는 코드
void thr(int a) {
	if (random == a) {
		printf("나 : 보 / 컴퓨터 : 보\n");
		printf("\n컴퓨터랑 잘 맞네\n\n");
		printf("현재 점수 : %d / %d\n\n", win, lose);

	}
	else if (random == 1) {
		printf("나 : 보 / 컴퓨터 : 가위\n");
		printf("\n졌습니다!\n\n");
		printf("현재 점수 : %d / %d\n\n", win, ++lose);
	}
	else if (random == 2) {
		printf("나 : 보 / 컴퓨터 : 바위\n");
		printf("\n이걸 이기네\n\n");
		printf("현재 점수 : %d / %d\n\n", ++win, lose);
	}
}

//난수 생성 및 가위 바위 보에 값에 따라 알맞은 함수로 보내주는 함수
void check(int key) {
	flag = 0;
	//난수 생성
	srand(time(NULL));
	random = (rand() % 3) + 1;
	//아스키코드 및 랜덤함수 작동 확인
	printf("\n%d %d\n\n", key, random);

	if (key == 49) one(1);
	else if (key == 50) two(2);
	else if (key == 51) thr(3);
}


//키입력
void in(int key) {
	key = _getch();
	if (key == 49) check(49);
	else if (key == 50) check(50);
	else if (key == 51) check(51);
	else {
		if (flag % 3 == 2) {
			if (flag % 9 != 2) printf("좀 제대로 입력하세요\n");
			else printf("똑바로 입력좀 하세요\n");
		}
		else if (flag == 9) printf("발로치시나요\n");
		else printf("다시 입력해주세요! \n");
		flag++;
		ch++;
		in(key);
	}
	return;
}

int main() {
	int key, flag_1 = 1;
	while (1) {
		if(ch==0)printf("   ㅡㅡㅡㅡ가위 바위 보 게임ㅡㅡㅡㅡ\nㅡㅡㅡㅡ시작하기 : y / 나가기 : rㅡㅡㅡㅡ\n\n");
		key = _getch();
		if (ch == 0 && key == 121) {
			ch++;
			printf("가위(1) / 바위(2) / 보(3) 중 한가지를 골라주세요!\n");
		}
		//나가기
		else if (key == 114) {
			printf("나가시겠습니까? (y/n)\n");
			key = _getch();
			if (key == 121) {
				return 0;
			}
			else ch = 0;
		}
		else {
			if (flag_1 == 3) {
				printf("\n혹시 발로 치시나요\n\n");
				flag_1++;
			}
			else if(flag_1 == 6) {
				printf("\n게임 안하겠다는 건가\n\n");
				flag_1++;
			}
			else if (flag_1 == 11) {
				printf("\n아 하지마\n\n");
				break;
			}
			else {
				printf("\n다시 입력해주세요!\n\n");
				flag_1++;
			}
		}
		if (ch != 0) {
			in(key);
			printf("\n다시하시겠습니까?(y/n)\n\n");
			key = _getch();
			if (key == 121) ch = 0;
			else break;
		}
		if (lose >= 5)printf("\n\n허접\n\n");
	}

	return 0;
}
