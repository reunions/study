#ifndef __COMPUTER_H__
#define __COMPUTER_H__
#include <stdio.h>

void computer() {
	xx1=0;
	yy1=0;
	player=2;
	value=0;
	maxmin(3,-9999,9999);		
	chessmap[row3][col3]=2;
	gotoxy(4*col3,2*row3);
	printf("¡ð");
}

#endif
