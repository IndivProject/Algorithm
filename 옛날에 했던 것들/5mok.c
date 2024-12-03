#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
 // 키보드 입력받는거

int flag = 0, i = 1, rock[28][28] = { 0 }, rock_2[28][28] = { 0 }; //0 = 판, 1 = 내가 수 둘곳, 1 = 내꺼, 2 = 상대꺼           rock_2에 돌 표시
int win_wh=1, win_bl=1, b_flag = 0, w_flag = 0;		//5면 승리
int win_countb, win_countw;
int sum = 1;	//상대 차레인지 내차례인지 확인용\

struct ij_count {
	int i = 10, j = 10;
};

struct ij_count ij;

// 앞으로 사용할 함수 명 : imjm = 0, imj = 0, imjp = 0, ijm = 0, ijp = 0, ipjm = 0, ipj = 0, ip = 0, jp = 0;
//가로

void jm_w(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i][ij.j -i] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i][ij.j +i] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	return;
}

void jm_b(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i][ij.j - i] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i][ij.j + i] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	return;
}

//세로
void im_w(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i - i][ij.j] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i + i][ij.j] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	return;
}

void im_b(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i - i][ij.j] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i + i][ij.j] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	return;
}

//대각선
void imjp_w(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i - i][ij.j + i] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i + i][ij.j - i] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	return;
}

void imjp_b(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i - i][ij.j + i] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i + i][ij.j - i] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	return;
}

void imjm_w(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i - i][ij.j - i] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i + i][ij.j + i] == a) {
			win_wh++;
			printf("%d,", win_wh);
		}
		else break;
	}
	return;
}

void imjm_b(int a) {
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i - i][ij.j - i] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	for (int i = 1; i <= 5; i++) {
		if (rock_2[ij.i + i][ij.j + i] == a) {
			win_bl++;
			printf("%d,", win_bl);
		}
		else break;
	}
	return;
}

void win_w() {
	//대각선
	if (rock_2[(ij.i - 1)][(ij.j - 1)] == 2 || rock_2[(ij.i + 1)][(ij.j + 1)] == 2) {
		imjm_w(2);
		if (win_wh >= 5) {
			w_flag++;
			return;
		}
		else {
			win_wh = 1;
		}
	}
	if (rock_2[ij.i - 1][ij.j + 1] == 2 || rock_2[ij.i + 1][ij.j - 1] == 2) {
		imjp_w(2);
		if (win_wh >= 5) {
			w_flag++;
			return;
		}
		else {
			win_wh = 1;
		}
	}
	//세로
	if (rock_2[ij.i - 1][ij.j] == 2 || rock_2[ij.i + 1][ij.j] == 2) {
		im_w(2);
		if (win_wh >= 5) {
			w_flag++;
			return;
		}
		else {
			win_wh = 1;
		}
	}
	//가로
	if (rock_2[ij.i][ij.j - 1] == 2 || rock_2[ij.i][ij.j + 1] == 2) {
		jm_w(2);
		if (win_wh >= 5) {
			w_flag++;
			return;
		}
		else {
			win_wh = 1;
		}
	}
}

void win_b() {
	if (rock_2[(ij.i - 1)][(ij.j - 1)] == 1 || rock_2[(ij.i + 1)][(ij.j + 1)] == 1) {
		imjm_b(1); 
		if (win_bl >= 5) {
			b_flag++;
			return;
		}
		else {
			win_bl = 1;
		}
	}
	if (rock_2[ij.i - 1][ij.j + 1] == 1 || rock_2[ij.i + 1][ij.j - 1] == 1) {
		imjp_b(1);
		if (win_bl >= 5) {
			b_flag++;
			return;
		}
		else {
			win_bl = 1;
		}
	}
	if (rock_2[ij.i - 1][ij.j] == 1 || rock_2[ij.i + 1][ij.j] == 1) {
		im_b(1);
		if (win_bl >= 5) {
			b_flag++;
			return;
		}
		else {
			win_bl = 1;
		}
	}
	if (rock_2[ij.i][ij.j - 1] == 1 || rock_2[ij.i][ij.j + 1] == 1) {
		jm_b(1);
		if (win_bl >= 5) {
			b_flag++;
			return;
		}
		else {
			win_bl = 1;
		}
	}
}


//엔터입력 
void enter_down() {
	if(rock_2[ij.i][ij.j] == 1 || rock_2[ij.i][ij.j] == 2) flag++;//같은곳에 뒀는지 확인
	else {
		if (sum % 2 != 0) {
			rock_2[ij.i][ij.j] = { 1 };
			sum++;
		}
		else if (sum % 2 == 0) {
			rock_2[ij.i][ij.j] = { 2 };
			sum++;
		}
		flag = 0;
	}
	return;

}

//키 입력
void w_keydown() {
	if ((ij.i - 1) == 0) return;
	if (rock[(ij.i - 1)][ij.j] == 0) {//&& rock_2[ij.i-1][ij.j] == 0
		rock[(ij.i - 1)][ij.j] = 1;
		rock[ij.i][ij.j] = 0;
		ij.i--;
	}
	return;
}

void a_keydown() {
	if ((ij.j - 1) == 0) return;
	if (rock[ij.i][(ij.j - 1)] == 0) {
		rock[ij.i][(ij.j - 1)] = 1;
		rock[ij.i][ij.j] = 0;
		ij.j--;
	}
	return;
}

void s_keydown() {
	if ((ij.i + 1) == 21) return;
	if (rock[(ij.i + 1)][ij.j] == 0) {
		rock[(ij.i + 1)][ij.j] = 1;
		rock[ij.i][ij.j] = 0;
		ij.i++;
	}
	return;
}

void d_keydown() {
	if ((ij.j + 1) == 21) return;
	if (rock[ij.i][(ij.j + 1)] == 0) {
		rock[ij.i][(ij.j + 1)] = 1;
		rock[ij.i][ij.j] = 0;
		ij.j++;
	}
	return;
}

void i_1(int j) {
	if (j == 1)	printf("\u250c ");
	else if (j == 20)printf("\u2510 ");
	else printf("\u252c ");
	return;
}

void i_mid(int j) {
	if (j == 1) printf("\u251c ");
	else if (j == 20)printf("\u2524 ");
	else printf("\u253c ");
	return;
}

void i_27(int j) {
	if (j == 1) printf("\u2514 ");
	else if (j == 20)printf("\u2518 ");
	else printf("\u2534 ");
	return;
}



//판짜는거
void pan2(int i) {
	for (int k = 1; k < 21; k++) {
		if (rock[i][k] == 0 && rock_2[i][k] != 0) {
			if (rock_2[i][k] == 1) printf("\u25CB");
			else if (rock_2[i][k] == 2) printf("\u25CF");
		}
		else {
			if (rock[i][k] == 0) {
				if (i == 1) i_1(k);
				else if (i == 20) i_27(k);
				else i_mid(k);
			}
			else {
				printf("\u0398");
			}
		}
	}
	return;
}

void pan() {
	for (i = 1; i < 21; i++) {
		pan2(i);
		printf("\n");
	}
	printf("\n");
	return;
}


//판 초기화
void zero() {
	for (int i = 0; i < 28; i++) {
		for(int j = 0; j < 28; j++) {
			rock_2[i][j] = 0;
		}
	}
	rock[ij.i][ij.j] = { 0 };
	ij.i = 10; ij.j = 10;
	rock[10][10] = { 1 };
	sum = 1;
	win_bl = 1;	win_wh = 1;	w_flag = 0;	b_flag = 0;
	return;
}



int main() {
	int key, cot = 1, bl=0, wh=0;
	rock[10][10] = { 1 };
	while (1) {
		printf("flag = %d win_wh = %d win_bl = %d",flag, wh, bl);
		bl = win_bl;
		wh = win_wh;
		printf("현재 좌표 :  %d %d\n", ij.i, ij.j);
		pan();
		if (cot != 1) printf("\n               (오목게임 히히)\n\n             방향키 :   W\n                       ASD\n         다시하기 : r        나가기 : n\n                 수 놓는 키 : Enter\n");
		if (cot == 1) printf("\n               (오목게임 히히)\n\n          Y : 시작		방향키 :   W\n          N : 나가기                      ASD\n\n\n");
		key = _getch();	//키보드 키값 받는거
		//키보드 wasd 입력받는거
		if (cot != 1) {
			if (key == 119) w_keydown();
			else if (key == 97) a_keydown();
			else if (key == 115) s_keydown();
			else if (key == 100) d_keydown();
			//엔터 받기
			if (key == 13) {
				enter_down();
				if(sum%2==0)win_b();
				else if(sum%2!=0)win_w();
				if (rock_2[ij.i][ij.j] == 0) sum--;
				rock[ij.i][ij.j] = { 0 };
				rock[10][10] = { 1 };
				ij.i = 10; ij.j = 10;
				//bot();	//입력 확인되면 봇으로 수 두기			-나락-
			}
		}
		bl = win_bl;
		wh = win_wh;
		//이기는거 정리

		if (w_flag) {
			printf("\n하양(후공)이 이겼습니다.\n다시하시겠습니까? (Y)\n");
			key = _getch();
			if (key == 121) {
				cot = 0;
				zero();
				printf("\n");
			}
			else break;
		}
		else if (b_flag) {
			printf("\n검정(선공)이 이겼습니다.\n다시하시겠습니까? (Y)\n");
			key = _getch();
			if (key == 121) {
				cot = 0;
				zero();
				printf("\n");
			}
			else break;
		}
		//아니면 다시 초기화
		if (key != 121) cot--;	//y안누르면 시작 못하게 하기
		if (key == 114) {		//r키 받기
			printf("다시 하시겠습니까? (Y/N)");
			key = _getch();
			if (key == 121) {
				cot = 0;
				zero();
				printf("\n");
			}
		}
		if (key == 110) {
			printf("\n나가시겠습니까? (Y/N)       ");
			key = _getch();
			if (key == 121) return 0;
			printf("\n");
		}
		cot++;
		printf("%d ", key);
	}
	return 0;
}