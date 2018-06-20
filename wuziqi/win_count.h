#ifndef __WIN_COUNT_H__
#define __WIN_COUNT_H__
#include <stdio.h>
//初始化并且重置对局
void initial() {
	memset(chessmap,0,sizeof(chessmap));
	weizhi.x=7;
	weizhi.y=9;
	gotoxy(weizhi.x, weizhi.y);
	system("cls");
}
//判断棋是否获得游戏胜利
int judge_win(int x,int y,int z) {
	int i=x;
	int j=y;
	int count_b=0;
	while(chessmap[i][j]==z&&i<=len-1) {
		i++;
		count_b++;
	}
	i=x-1;
	while(chessmap[i][j]==z&&i>=0) {
		i--;
		count_b++;
	}
	if(count_b>4) {
		return 1;
	}
	i=x,j=y,count_b=0;
	while(chessmap[i][j]==z&&j<=len-1) {
		j++;
		count_b++;
	}
	j=y-1;
	while(chessmap[i][j]==z&&j>=0) {
		j--;
		count_b++;
	}
	if(count_b>4) {
		return 1;
	}
	i=x,j=y,count_b=0;
	while(chessmap[i][j]==z&&i>=0&&j<len) {
		i--;
		j++;
		count_b++;
	}
	i=x+1,j=y-1;
	while(chessmap[i][j]==z&&i<len&&j>=0) {
		i++;
		j--;
		count_b++;
	}
	if(count_b>4) {
		return 1;
	}
	i=x,j=y,count_b=0;
	while(chessmap[i][j]==z&&i<len&&j<len) {
		i++;
		j++;
		count_b++;
	}
	i=x-1,j=y-1;
	while(chessmap[i][j]==z&&i>=0&&j>=0) {
		i--;
		j--;
		count_b++;
	}
	if(count_b>4) {
		return 1;
	}
	return 0;

}


int chessjudge(int x,int y) {
	if(chessmap[x][y]==0)return 1;
	return 0;

}


int judge_count(int x,int y,int z) {
	int count3, count4, sumscore =1;
	char u, d, l, r, lu, ld, ru, rd;    //u上 d下 l左 r右 lu左斜上 ld左斜下 ru右斜上 rd右斜下
	int row, col, count1, count2;   //表示横向 竖向 斜上 斜下


	count1 = count2 = count3 = count4 = 1;
	l = r = u = d = lu = ld = ru = rd = 0;

	row = x, col = y + 1;
	while (chessmap[row][col] ==z && col < len) {
		count1++;
		col++;
	}
	while (col < len && chessmap[row][col] == 0) {
		r++;
		col++;
	}
	row = x, col = y - 1;
	while (chessmap[row][col] == z && col >= 0) {
		count1++;
		col--;
	}
	while (col >= 0 && chessmap[row][col] == 0) {
		l++;
		col--;
	}

	row = x + 1, col = y;
	while (chessmap[row][col] == z && row < len) {
		count2++;
		row++;
	}
	while (row < len && chessmap[row][col] == 0) {
		d++;
		row++;
	}
	row = x - 1, col = y;
	while (chessmap[row][col] == z && row >= 0) {
		count2++;
		row--;
	}
	while (row >= 0 && chessmap[row][col] == 0) {
		u++;
		row--;
	}

	//判断斜上向棋子并记录空格子
	row = x - 1, col = y + 1;
	while (chessmap[row][col] ==z && col < len && row >= 0) {
		count3++;
		col++;
		row--;
	}
	while (col < len && row >= 0 && chessmap[row][col] == 0) {
		ru++;
		col++;
		row--;
	}
	row = x + 1, col = y - 1;
	while (chessmap[row][col] == z && col >= 0 && row < len) {
		count3++;
		col--;
		row++;
	}
	while (col >= 0 && row < len && chessmap[row][col] == 0) {
		ld++;
		col--;
		row++;
	}
	row = x + 1, col = y + 1;
	while (chessmap[row][col] == z && col < len && row < len) {
		count4++;
		col++;
		row++;
	}
	while (col < len && row < len && chessmap[row][col] == 0) {
		rd++;
		col++;
		row++;
	}
	row = x - 1, col = y - 1;
	while (chessmap[row][col] == z&& col >= 0 && row >= 0) {
		count4++;
		col--;
		row--;
	}
	while (col >= 0 && row >= 0 && chessmap[row][col] == 0) {
		lu++;
		col--;
		row--;
	}
	if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5) {  //判断五子
		return sumscore = 10000;
	}
	if ((count1 == 4 && count2 == 4 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
	        (count1 == 4 && count3 == 4 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
	        (count1 == 4 && count4 == 4 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
	        (count2 == 4 && count3 == 4 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
	        (count2 == 4 && count4 == 4 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
	        (count3 == 4 && count4 == 4 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1)) { //判断双活四
		return sumscore = 4000;
	}

	if ((count1 == 4 && l >= 1 && r >= 1) || (count2 == 4 && u >= 1 && d >= 1) ||
	        (count3 == 4 && ru >= 1 && ld >= 1) || (count4 == 4 && lu >= 1 && rd >= 1)) { //判断活四
		return sumscore = 2000;
	}
	if ((count1 == 4 && ((l == 0 && r >= 1) || (l >= 1 && r == 0))) || (count2 == 4 && ((u == 0 && d >= 1) || (u >= 1 && d == 0))) ||
	        (count3 == 4 && ((ld == 0 && ru >= 1) || (ld >= 1 && ru == 0))) || (count4 == 4 && ((lu == 0 && rd >= 1) || (lu >= 1 && rd == 0)))) {
		return  sumscore = 850;  //成四
	}
	if( ( count1 == 3 && count2 == 3 && l >=1 && r >=1 && u >=1 && d >=1) ||
	        ( count1 == 3 && count3 == 3 && l >=1 && r >=1 && ru >=1 && ld >=1 ) ||
	        ( count1 == 3 && count4 == 3 && l >=1 && r >=1 && rd >=1 && lu >=1 ) ||
	        ( count2 == 3 && count3 == 3 && u >=1 && d >=1 && ru >=1 && ld >=1 ) ||
	        ( count2 == 3 && count4 == 3 && u >=1 && d >=1 && lu >=1 && rd >=1 ) ||
	        ( count3 == 3 && count4 == 3 && ru >=1 && ld >=1 && lu >=1 && rd >=1) ) { //判断双活三
		return sumscore = 900;
	}
	if ((count1 == 3 && l >= 1 && r >= 1) || (count2 == 3 && u >= 1 && d >= 1) ||
	        (count3 == 3 && ru >= 1 && ld >= 1) || (count4 == 3 && lu >= 1 && rd >= 1)) {
	
		return sumscore= 300;
	}     //判断活三
	if ((count1 == 2 && count2 == 2 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
	        (count1 == 2 && count3 == 2 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
	        (count1 == 2 && count4 == 2 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
	        (count2 == 2 && count3 == 2 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
	        (count2 == 2 && count4 == 2 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
	        (count3 == 2 && count4 == 2 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1)) {
		sumscore = sumscore + 20;   //判断双活二
	}
	if ((count1 == 2 && l >= 1 && r >= 1) || (count2 == 2 && u >= 1 && d >= 1) ||
	        (count3 == 2 && ru >= 1 && ld >= 1) || (count4 == 2 && lu >= 1 && rd >= 1)) {
		sumscore = sumscore + 10;     //单活二
	}
	return sumscore;
}

#endif
