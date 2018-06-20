#ifndef __BOARD_H__
#define __BOARD_H__
#include <stdio.h>

int chessmap[len][len];//��������
//��Ϸ��ʼ����//

//�������λ�Ƶĺ���//
struct zuobiao {
	int x;
	int y;
} weizhi= {7,9}; //��������ṹ��

void gotoxy(int x,int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void start_game() {
	gotoxy(0,10);
	printf("--------------------------------------------------------------------------\n"); 
	printf("-----------------------------������С��Ϸ---------------------------------\n");
	printf("-------------------------- ������--���Ժ����-----------------------------\n");
	printf("-----------------------���������ʼ�͵��Խ���������-----------------------\n"); 
	printf("--------------------------------------------------------------------------\n");
	
}

//�̻�����//
void board_chessprint() {
	for (int j = 0; j<len; j++) {
		for (int i = 0; i<len; i++) {
			if (chessmap[j][i] == 1)
				printf("��");
			else if (chessmap[j][i] == 2)
				printf("��");
			else if (j == 0 && i == 0)
				printf("��");
			else if (j == 0 && i == len - 1)
				printf("��");
			else if (j == len - 1 && i == 0)
				printf("��");
			else if (j == len - 1 && i == len - 1)
				printf("��");
			else if (j == 0 && i != 0 && i != len - 1)
				printf("��");
			else if (j != 0 && j != len - 1 && i == 0)
				printf("��");
			else if (j != 0 && j != len - 1 && i == len - 1)
				printf("��");
			else if (j == len - 1 && i != 0 && i != len - 1)
				printf("��");
			else if (j != 0 && j != len - 1 && i != 0 && i != len - 1)
				printf("��");

			if (j>0 && j<len - 1 && i<len - 1)
				printf("��");
			if (j == 0 && i != len - 1)
				printf("��");
			else if (j == len - 1 && i != len - 1)
				printf("��");
		}
		printf("\n");


		if (j >= 0 && j<len - 1) {
			for (int k = 0; k<len; k++) {
				if (k == 0 || k == len - 1)
					printf("��  ");
				else printf("��  ");
			}

			if (j == 2)
				printf(" �� ���� ��");
			if(j == 4)
				printf(" �� �ո�����  ��");
			if(j == 6)
				printf(" ��  �ƶ���� ��");
			if(j == 8)
				printf(" ����,��,��,�ҡ�");
			if(j==10)
				printf(" ����ESC�˳���Ϸ��"); 
		}
		printf("\n");
	}
}


void movechess(char key) {
	switch(key) {
			//��������
		case 0x48:
			if(weizhi.y>=0)weizhi.y--;
			if(weizhi.y<0)weizhi.y=len-1;
			break;
			//��������
		case 0x50:
			if(weizhi.y<=len-1)weizhi.y++;
			if(weizhi.y>len-1)weizhi.y=0;
			break;
			//��������
		case 0x4B:
			if(weizhi.x>=0)weizhi.x--;
			if(weizhi.x<0)weizhi.x=len-1;
			break;
			//��������
		case 0x4D:
			if(weizhi.x<=len-1)weizhi.x++;
			if(weizhi.x>len-1)weizhi.x=0;
			break;
	}
	gotoxy(4 * weizhi.x, 2 * weizhi.y);
}
#endif
