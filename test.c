#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXROW 10
#define MAXCOL 10
#define MINE_COUNT 10
int menu(){
	printf("------------------\n");
	printf("输入0结束游戏\n");
	printf("输入1开始游戏\n");
	printf("------------------\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
void init(char showmap[MAXROW + 2][MAXCOL + 2],
	char minemap[MAXROW + 2][MAXCOL + 2]){
	//初始化showmap；
	for (int row = 0; row < MAXROW+2; ++row){
		for (int col=0;col<MAXCOL+2 ;++col){
			showmap[row][col] = '*';
		}
	}
	//初始化minemap
	for (int row = 0; row < MAXROW+2; ++row){
		for (int col = 0; col<MAXCOL+2; ++col){
			minemap[row][col] = '0';
		}
	}
	int i=MINE_COUNT;
	while ( i>0){
		int row = rand() % 10 + 1;
		int col = rand() % 10 + 1;
		if (minemap[row][col] == '1'){
			continue;
		}
		minemap[row][col] = '1';
		--i;
	}
}
void displaymap(char showmap[MAXROW+2][MAXCOL+2]){
	printf("     ");
	for (int i=1; i <= MAXCOL; ++i){
		printf("%d ", i);
	}
	printf("\n ");
	printf("   ");
	for (int i=1; i <= MAXCOL; ++i){
		printf("--");
	}
	printf("\n");
	for (int row = 1; row <= MAXROW;row++){
		printf("%02d | ", row);
		for (int col = 1; col <= MAXCOL; col++)
		{
			printf("%c ", showmap[row][col]);
		}
		printf("\n");
	}
}
void updatemap(char minemap[MAXROW + 2][MAXCOL + 2],
char showmap[MAXROW + 2][MAXCOL + 2],int col,int row){
	int count;
	count = (minemap[row][col - 1] - '0') +
		(minemap[row][col + 1] - '0') +
		(minemap[row + 1][col] - '0') +
		(minemap[row - 1][col] - '0') +
		(minemap[row - 1][col - 1] - '0') +
		(minemap[row + 1][col + 1] - '0') +
		(minemap[row + 1][col - 1] - '0') +
		(minemap[row - 1][col + 1] - '0');
	   showmap[row][col] = '0'+count;
}
void Game(){
	//进行一局游戏
	//需要两个二维数组表示地图
	//第一个数组表示地图
	//对于showmap如果位置没有掀开用*表示
	//如果掀开用一个具体的数字表示
	char showmap[MAXROW + 2][MAXCOL + 2];
	//第二个数组表示雷阵
	//mainemap里边的元素有以下几种情况
	//有雷为1没有雷0
	char minemap[MAXROW + 2][MAXCOL + 2];
	//初始化数组
	init(showmap,minemap);
	//打印出地图
	displaymap(showmap);
	while (1){
		//玩家输入坐标,判断坐标是否合法
		int row, col,count_remove=0;
		printf("请输入坐标(x y)\n");
		scanf("%d %d", &row, &col);
		if (row > MAXROW || row<=0 || col>MAXCOL || col <= 0){
			printf("输入错误再次输入:\n");
				continue;
		}
		//判定玩家是否踩雷
		//1.踩雷游戏结束
		if (minemap[row][col] == '1'){
			displaymap(minemap);
			printf("结束游戏\n");
			break;
		}
		++count_remove;
		//是不是掀开了所有的格子
		if(count_remove==MAXROW*MAXCOL-MINE_COUNT){
			displaymap(minemap);
			printf("恭喜获胜\n");
			break;
		}
		//如果没踩雷统计该位置周围有几个雷跟新地图
			updatemap(minemap,showmap,row,col);
			displaymap(showmap);
	}
}
void Start(){
	while (1){
		int choice = menu();
		if (choice == 0){
			printf("退出游戏\n");
			break;
		}
		else
			Game();
	}
}
int main(){
	//1.展示一个游戏菜单
	Start();
}