#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXROW 9
#define MAXCOL 9
#define MINE_COUNT 10
int menu(){
	printf("------------------\n");
	printf("输入0结束游戏\n");
	printf("输入0结束游戏\n");
	printf("------------------\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
void init(char minemap[MAXROW + 2][MAXCOL + 2],
	char showmap[MAXROW + 2][MAXCOL + 2]){
	//初始化showmap；
	for (int row = 0; row < MAXROW; ++row){
		for (int col=0;col<MAXCOL ;++col){
			showmap[row][col] = '*';
		}
	}
	//初始化minemap
	for (int row = 0; row < MAXROW; ++row){
		for (int col = 0; col<MAXCOL; ++col){
			minemap[row][col] = '0';
		}
	}
	int i=MINE_COUNT;
	while ( i>0){
		int row = rand() % 10 - 1;
		int col = rand() % 10 - 1;
		if (minemap[row][col] == '1'){
			continue;
		}
		minemap[row][col] = '1';
		i--;
	}
}
void displaymap(){
	printf("     ");
	for (int i; i <= MAXCOL; ++i){
		printf("%d ", i);
	}
	printf("\n ");
	for (int i; i <= MAXCOL; ++i){
		printf("---");
	}

}
void Game(){
	//初始化数组
	char minemap[MAXROW + 2][MAXCOL + 2];
	char showmap[MAXROW + 2][MAXCOL + 2];
	init(minemap[MAXROW + 2][MAXCOL + 2],
		showmap[MAXROW + 2][MAXCOL + 2]);
	//打印出是棋盘
	
}
void Start(){
	while (1){
		int choice = menu();
		if (choice == 1){
			Game();
		}
		else
			printf("退出游戏\n");
	}
}
int main(){
	//1.展示一个游戏菜单
	Start();
}