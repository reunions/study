#ifndef __PLAYGAME_H__
#define __PLAYGAME_H__
#include <stdio.h>

int w;  
int count=0;

void playgame() {
	char key;
	if(w==1) {
		initial();
		board_chessprint();
		w=0;
	}
	while(1) {
		key=getch();
		if(key==27) {
			exit(0);
		} else if(key==110) {
			break;
		} else if(key==32) {
			if(count==len*len) {
				printf("平局");
				count=0;
				break;
			} else {
				if(chessjudge(weizhi.y,weizhi.x)) {
					chessmap[weizhi.y][weizhi.x]=1;
					count++;
					printf("●");
				}
				if(judge_win(weizhi.y,weizhi.x,1)) {
					system("cls");
					board_chessprint();
					printf("黑子胜利\n");
					printf("按回车继续\n");
					w=1;
					getchar();
					break;
				}
				computer();
				if(judge_win(row3,col3,2)) {
					system("cls");
					board_chessprint();
					printf("白子胜利\n");
					printf("按回车继续\n");
					w=1;
					getchar();
					break;
				}
			}
		} else {
			key=getch();//光标
			movechess(key);
		}


	}
}

#endif
