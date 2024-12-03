#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>	//rand함수 - 난수 생성
#include <time.h>	//srand에 들어갈 time
#include <conio.h>	//키를 입력 받을 거
#include <Windows.h> //sleep

int key, be_mo, money = 2000, i = 0, win_lose = 0;//숫자가 겹치는지 확인
int sum_me = 0, sum_de = 0, me[10], de[10]; //카드 총합, 카드 받는 변수
int de_bu = 0, me_bu = 0, me_ch = 0, de_ch = 0, to_ch = 0;//딜러 버스트, 21체크

//win_lose - 1 : 짐, 2 : 이김, 3 : 비김
//de_bu : 딜러 버스트 확인, de_ch : 딜러 17이상인지 체크해주는거 ,me_ch : 카드 안뽑아도되는거 체크, to_ch : 21체크
//

int r = 0, es[50];	//이스터에그 관련
int f = 0; //딜러 카드 보여주는거

//다시할 경우 변수 초기화
void reset() {
	i = 0;
	r = 0;
	f = 0;
	win_lose = 0;
	sum_me = 0;
	sum_de = 0;
	me[10];
	de[10];
	me_ch = 0;
	de_ch = 0;
	me_bu = 0;
	de_bu = 0;
	to_ch = 0;
}

//...찍어주는거
void point_print() {
	printf("     .");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
}

//딜러 버스크 확인
void de_card_Ch() {
	if (sum_de > 21) {
		de_bu = 1;
	}
}

void card_ch() {
	//버스트 확인
	if (sum_me > 21) {
		printf("\n\n");
		printf("    .");
		Sleep(700);
		printf(".");
		Sleep(700);
		printf(".");
		Sleep(700);
		printf("버스트!...");
		Sleep(700);
		me_bu = 1;
		me_ch = 1;
	}
	//21이면 무조건 이김
	else if (sum_me == 21) {
		to_ch = 1;
		me_ch = 1;
		printf("\n\n");
		printf("    .");
		Sleep(700);
		printf(".");
		Sleep(700);
		printf(".");
		Sleep(700);
		if (i == 2) {
			printf("블랙잭..!");
		}
		else printf("21..!");
		Sleep(700);
		win_lose = 4;
	}
}

//카드 뽑기 고칠거 없
void card() {
	int random;
	srand(time(NULL));
	if (win_lose == 0 && me_ch == 0) {
		printf("   %d번째 카드뽑는중", i + 1);
		Sleep(700);
		printf(".");
		Sleep(700);
		printf(".");
		Sleep(700);
		printf(".\n");
		Sleep(700);
		random = (rand() % 10) + 2;	//내 카드 뽑기
		me[i] = random;
		sum_me += me[i];
	}
	if (sum_de < 15) {
		random = (rand() % 10) + 2;	//딜러 카드 뽑기
		de[i] = random;
		sum_de += de[i];
		de_card_Ch();
	}
	if (sum_de > 14) de_ch = 1;
	i++;
}
//출력해주는거
void line() {
	if (me_ch == 0) printf("\n===========================================\n\n");
	if (i == 0) card();
	card();
	if (me_ch == 0) {
		printf("\n   현재 가지고 있는 카드 : ");
		for (int j = 0; j < i; j++) {
			if (me[j] != 0) printf("%d ", me[j]);
		}
		Sleep(500);
		printf("\n\n          총합 : %d\n\n", sum_me);
	}
	if (i % 4 == 0) {
		if (de_ch == 0)f++;
	}
	for (int j = 0; j < f; j++) printf("      딜러의 %d번째 카드 : %d\n\n", j, de[j]);
	if (me_ch == 0)card_ch();
	if (to_ch == 1) return;
	if (de_ch == 1 && me_ch == 1) return;
	//카드 뽑는거
	if (me_ch == 0) {
		printf("    더 뽑으시겠습니까? (Y/N)    >>");
		printf("\n\n\n\n");
		key = _getch();
		if (key == 121) line();
		else if (key == 110) {
			if (sum_me < 15) {
				printf("\n     값이 너무 작습니다!\n\n");
				line();
			}
			me_ch = 1;
			printf("    현재 카드 총합 >> %d\n\n", sum_me);
		}
	}
	else if (me_ch == 1 && de_ch == 0) {
		printf("\n\n    딜러 카드 뽑는중");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
		Sleep(500);
		printf(".");
	}
	line();
}
//카드 마지막 체크(버스트, 버스트 / 버스트, 이김 / 이김, 버스트 / 이김, 이김 -> 이김, 비김, 짐)
void last_ch() {
	if (de_bu == 1 && me_bu == 1) {
		win_lose = 3;
	}
	else if (de_bu == 1 && me_bu == 0) {
		win_lose = 2;
	}
	else if (de_bu == 0 && me_bu == 1) {
		win_lose = 1;
	}
	else if (de_bu == 0 && me_bu == 0) {
		if (sum_de == sum_me) win_lose = 3;
		else if (sum_de > sum_me) win_lose = 1;
		else win_lose = 2;
	}
}

//이긴지 진지 체크 해주는거
void win_lose_ch() {
	if (win_lose == 1) {
		point_print();
		printf("졌습니다..!\n\n");
		Sleep(1000);
		printf("    %d를 잃어버리셨습니다...\n\n", be_mo);
		money -= be_mo;
	}
	else if (win_lose == 2) {
		point_print();
		printf("이겼습니다..!\n\n");
		Sleep(1000);
		printf("    %d를 벌으셨습니다..!\n\n", be_mo);
		money += be_mo;
	}
	else if (win_lose == 3) {
		point_print();
		printf("비겼습니다..?\n\n");
		Sleep(1000);
		printf("    비겨서 돈을 그대로 돌려드립니다.\n\n", be_mo);
	}
	else if (win_lose == 4) {
		point_print();
		if (sum_de == sum_me) {
			printf("비겼습니다..?\n\n");
			Sleep(1000);
			printf("    비겨서 돈을 그대로 돌려드립니다.\n\n", be_mo);
		}
		else {
			printf("21로 이겼습니다..!\n\n");
			Sleep(1000);
			printf("    %d를 벌으셨습니다..!\n\n", be_mo);
			money += be_mo;
		}
	}
	Sleep(500);
}

//배팅 다시하는거
void re_mo() {
	printf("\n\n\t값이 너무 크거나 작습니다! \n\t다시 입력해주세요!  >>  ");
	scanf("%d", &be_mo);
	if (be_mo > money || be_mo < 200) re_mo();
}

//올인
void all_in() {
	printf("\n   오.");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(1000);
	printf("오.. ");
	Sleep(500);
	printf("올인 하셨습니다!  \n");
	Sleep(700);
}

//게임
void game() {
	printf("       게임이 시작되었습니다!\n");
	Sleep(1000);
	printf("        현재 소지금액 : % d\n\n    얼마를 배팅하시겠습니까 ? >> ", money);
	scanf("%d", &be_mo);
	if (be_mo > money || be_mo < 200) re_mo();
	if (be_mo == money) all_in();
	else printf("\n	   %d이 배팅 되었습니다!\n\n", be_mo);
	Sleep(1000);
	printf("\n\n       게임이 시작됩니다..\n");
	Sleep(3000);
	printf("\n\n   -----게임 시작!-----");
	line();
	printf("\n\n   -----카드 뽑기가 끝났습니다!-----\n\n");
	if (win_lose == 0)last_ch();
	win_lose_ch();
	printf("\n  딜러의 카드 총합은 %d", sum_de);
	if (de_bu == 1) printf(", 버스트 였습니다!\n");
	else printf("였습니다!\n");
	Sleep(1000);
}

//이스터에그
void ester() {
	if (es[r] == 109) {
		if (es[r - 1] == 103 && es[r - 2] == 98) {
			system("cls");
			Sleep(300);
			printf("       _                   _____           _       _   \n");
			Sleep(300);
			printf("      | |                 / ____|         (_)     | |  \n");
			Sleep(300);
			printf("      | | __ ___   ____ _| (___   ___ _ __ _ _ __ | |_ \n");
			Sleep(300);
			printf("  _   | |/ _` \\ \\ / / _` |\\___ \\ / __| '__| | '_ \\| __|\n");
			Sleep(300);
			printf(" | |__| | (_| |\\ V / (_| |____) | (__| |  | | |_) | |_ \n");
			Sleep(300);
			printf("  \\____/ \\__,_| \\_/ \\__,_|_____/ \\___|_|  |_| .__/ \\__|\n");
			Sleep(300);
			printf("                                            | |        \n");
			Sleep(300);
			printf("                                            |_|        \n");
			Sleep(3000);

			system("cls");
			printf("\n\n     다시 입력해주세요!\n\n");
		}
	}
	else if (es[r] == 107) {
		if (es[r - 1] == 99 && es[r - 2] == 97 && es[r - 3] == 106 && es[r - 4] == 107 && es[r - 5] == 99 && es[r - 6] == 97 && es[r - 7] == 108 && es[r - 8] == 98) {
			system("cls");
			Sleep(300);
			printf(" ___    _                  _      _____                _     \n");
			Sleep(300);
			printf("(  _`\\ (_ )               ( )    (___  )              ( )    \n");
			Sleep(300);
			printf("| (_) ) | |    _ _    ___ | |/')     | |   _ _    ___ | |/')\n");
			Sleep(300);
			printf("|  _ <' | |  /'_` ) /'___)| , <   _  | | /'_` ) /'___)| , <  \n");
			Sleep(300);
			printf("| (_) ) | | ( (_| |( (___ | |\\`\\ ( )_| |( (_| |( (___ | |\\`\\ \n");
			Sleep(300);
			printf("(____/'(___)`\\__,_)`\\____)(_) (_)`\\___/'`\\__,_)`\\____)(_) (_)\n\n");
			Sleep(2000);
		}
	}
}

void start() {
	printf("\u25A0\u25A1\u25A0\u25A1\u25A0\u25A1\u25A0\u25A1\u25A0          *룰 : 카드합이 총합 21이 넘으면 안되며 시작하면 두장의 카드를 지급합니다.\n");
	Sleep(200);
	printf("\u25A1              \u25A1                컴퓨터와 1대1로 대결을 하며 컴퓨터는 카드합이 15가 넘기전까지 카드를 계속 뽑습니다.\n");
	Sleep(200);
	printf("\u25A0  Black Jack  \u25A0                배팅은 200부터 할 수 있으며 초기 2000이 지급됩니다.\n");
	Sleep(200);
	printf("\u25A1              \u25A1                A는 11로 칩니다.\n");
	Sleep(200);
	printf("\u25A0\u25A1\u25A0\u25A1\u25A0\u25A1\u25A0\u25A1\u25A0\n\n\n");
}

int main() {
	int flag = 0;
	while (1) {
		if (flag == 0) start();
		printf("		시작하기 : Y / 나가기 : N\n\n");
		key = _getch();
		if (key == 121) {
			game();
			flag++;
			Sleep(700);
			printf("\n\n    현재 가진 금액 : %d\n\n", money);
			Sleep(700);
			if (money == 0) {
				printf("\n\n배팅하실 돈이 없어 카지노에서 쫓겨났습니다....\n");
				return 0;
			}
			printf("\n\n    다시하시겠습니까? (Y/N)\n\n");
			key = _getch();
			if (key == 110) {
				Sleep(300);
				printf("      계산중");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(500);
				printf(".");
				Sleep(1500);
				printf("\n\n          따거나 잃은 총 금액 >> %d\n\n", money - 2000);
				break;
			}
			else if (key == 121) {
				system("cls");
				printf("\n\n");
				reset();
			}
		}
		else if (key == 110) {
			printf("      나가시겠습니까? (Y/N)\n\n");
			key = _getch();
			if (key == 121) break;
		}
		else {
			printf("   다시 입력해주세요! %d\n", key);
			es[r] = key;
			flag++;
			ester();
			r++;
			if (r == 50) r = 0;
		}
	}
	return 0;
}