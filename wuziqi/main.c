#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define len 15
#include "board.h"
#include "win_count.h"
#include "maxmin.h"
#include "computer.h"
#include "playgame.h"

int main(){
	system("title 玩家 vs Amadeus ");//设置标题  
    system("mode con cols=100 lines=35");//设置窗口大小  
    system("color E0");//颜色 
    char asd;
	start_game();
	asd=getch();
	system("cls");
	while(1) {
		board_chessprint();
		playgame();
		system("cls");
	}
	return 0;
}


