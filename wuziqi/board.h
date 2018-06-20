#ifndef __BOARD_H__
#define __BOARD_H__
#include <stdio.h>

int chessmap[len][len];//棋盘数组
//游戏开始界面//

//建立光标位移的函数//
struct zuobiao {
	int x;
	int y;
} weizhi= {7,9}; //构建坐标结构体

void gotoxy(int x,int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void start_game() {
	gotoxy(0,10);
	printf("--------------------------------------------------------------------------\n"); 
	printf("-----------------------------五子棋小游戏---------------------------------\n");
	printf("-------------------------- 制作者--凤凰院凶真-----------------------------\n");
	printf("-----------------------按任意键开始和电脑较量较量吧-----------------------\n"); 
	printf("--------------------------------------------------------------------------\n");
	
}

//刻画棋盘//
void board_chessprint() {
	for (int j = 0; j<len; j++) {
		for (int i = 0; i<len; i++) {
			if (chessmap[j][i] == 1)
				printf("●");
			else if (chessmap[j][i] == 2)
				printf("○");
			else if (j == 0 && i == 0)
				printf("┏");
			else if (j == 0 && i == len - 1)
				printf("┓");
			else if (j == len - 1 && i == 0)
				printf("┗");
			else if (j == len - 1 && i == len - 1)
				printf("┛");
			else if (j == 0 && i != 0 && i != len - 1)
				printf("┯");
			else if (j != 0 && j != len - 1 && i == 0)
				printf("┠");
			else if (j != 0 && j != len - 1 && i == len - 1)
				printf("┨");
			else if (j == len - 1 && i != 0 && i != len - 1)
				printf("┷");
			else if (j != 0 && j != len - 1 && i != 0 && i != len - 1)
				printf("┼");

			if (j>0 && j<len - 1 && i<len - 1)
				printf("—");
			if (j == 0 && i != len - 1)
				printf("━");
			else if (j == len - 1 && i != len - 1)
				printf("━");
		}
		printf("\n");


		if (j >= 0 && j<len - 1) {
			for (int k = 0; k<len; k++) {
				if (k == 0 || k == len - 1)
					printf("┃  ");
				else printf("│  ");
			}

			if (j == 2)
				printf(" 【 操作 】");
			if(j == 4)
				printf(" 【 空格下子  】");
			if(j == 6)
				printf(" 【  移动光标 】");
			if(j == 8)
				printf(" 【上,下,左,右】");
			if(j==10)
				printf(" 【按ESC退出游戏】"); 
		}
		printf("\n");
	}
}


void movechess(char key) {
	switch(key) {
			//坐标上移
		case 0x48:
			if(weizhi.y>=0)weizhi.y--;
			if(weizhi.y<0)weizhi.y=len-1;
			break;
			//坐标下移
		case 0x50:
			if(weizhi.y<=len-1)weizhi.y++;
			if(weizhi.y>len-1)weizhi.y=0;
			break;
			//坐标左移
		case 0x4B:
			if(weizhi.x>=0)weizhi.x--;
			if(weizhi.x<0)weizhi.x=len-1;
			break;
			//坐标右移
		case 0x4D:
			if(weizhi.x<=len-1)weizhi.x++;
			if(weizhi.x>len-1)weizhi.x=0;
			break;
	}
	gotoxy(4 * weizhi.x, 2 * weizhi.y);
}
#endif
