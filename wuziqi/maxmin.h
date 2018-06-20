#ifndef __MAXMIN_H__
#define __MAXMIN_H__
#include <stdio.h>
int xx1=0;
int yy1=0;
int player=2;
int value;
int row3=0;
int col3=0;


int maxmin(int deep,int alpha,int beta){
	
	
	if(judge_win(xx1,yy1,2)==1||judge_win(xx1,yy1,1)==1){
		return 10000;
	}
	if(deep==0){
		return judge_count(xx1,yy1,player); 
	} 
	if(player==2){
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(chessjudge(i,j)){
					chessmap[i][j]=2;
					player=1;
					xx1=i;
					yy1=j;
					value=maxmin(deep-1,alpha,beta);
					chessmap[i][j]=0;
					if(value>alpha){
							alpha=value;
							row3=i;
					        col3=j;
					}
					if(alpha>beta){
						return alpha;
					}
						
				}
			}
		}
		return alpha;
	}
	else if(player==1){
		for(int i=0;i<len;i++){
			for(int j=0;j<len;j++){
				if(chessjudge(i,j)){
					chessmap[i][j]=1;
					player=2;
					xx1=i;
					yy1=j;
					value=maxmin(deep-1,alpha,beta); 
					chessmap[i][j]=0;
					if(value<beta){
						beta=value;
						
					}
					if(alpha>beta){
						return beta;
					}
						
				}
			}
		}
		return beta;
	}
}
#endif
