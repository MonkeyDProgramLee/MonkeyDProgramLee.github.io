#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
char g_checkerboard[ROW][COL];
void Init(){
	int row, col;
	for (row = 0; row < ROW; ++row){
		for (col = 0; col < COL; ++col){
			g_checkerboard[row][col] = ' ';
		}
	}
}
void Print(){
	for (int row = 0; row < ROW; ++row){
		if (row == 0){
			printf(" -----------\n");
		}
		printf("| %c | %c | %c |\n", 
			g_checkerboard[row][0],
			g_checkerboard[row][1],
			g_checkerboard[row][2]);
		printf(" -----------\n");
	}
}
void Playermove(){
	int row, col;
	while (1){
		printf("请输入下子的坐标：\n");
		scanf("%d,%d", &row, &col);
		if (row<0 || row>=ROW || col<0 || col>=COL ||
			g_checkerboard[row][col] != ' '){
			printf("输入有误请再次输入");
			continue;
		}
		else{
			g_checkerboard[row][col] = 'o';
			break;
		}
	}
}
char Checkwinner(){
	int col, row, count = 0;
	//玩家赢
	//1.判断行
	for (row = 0; row < ROW; ++row){
		if (g_checkerboard[row][0] == 'o'&& g_checkerboard[row][1] == 'o'&&
			g_checkerboard[row][2]=='o')
			return 'o';
	}
	//2.判断列
	for (col = 0; col < col; ++col){
		if (g_checkerboard[0][col] =='o' &&
			g_checkerboard[1][col] == 'o'&&
			g_checkerboard[2][col]=='o')
			return 'o';
	}
	//3.判断对角线
	if (g_checkerboard[0][0] == 'o'&& g_checkerboard[1][1] == 'o'&&
		g_checkerboard[2][2] == 'o' ||
		g_checkerboard[0][2] == 'o'&& g_checkerboard[1][1] == 'o'&&
		g_checkerboard[2][0] == 'o')
		return 'o';
	//电脑赢
	////1.判断行
	for (row = 0; row < ROW; ++row){
		if (g_checkerboard[row][0] =='x' && g_checkerboard[row][1] == 'x'&&
			g_checkerboard[row][2]=='x')
			return 'x';
	}
	////判断列
	for (col = 0; col < COL; ++col){
		if (g_checkerboard[0][col] == 'x'&&g_checkerboard[1][col] == 'x'
			&&g_checkerboard[2][col]=='x')
			return 'x';
	}
	//判断对角线
	if (g_checkerboard[0][0] = 'x'&& g_checkerboard[1][1] == 'x'&&
		g_checkerboard[2][2] == 'x' ||
		g_checkerboard[0][2] == 'x'&&g_checkerboard[1][1] == 'x'&&
		g_checkerboard[2][0] == 'x')
		return 'x';
	////判断平局
	for (row = 0; row < ROW; ++row){
		for (col = 0; col < COL; ++col){
			if (g_checkerboard[row][col] == ' ')
				break;
			else
				count++;
		}
	}
	if (count == COL*ROW)
		return '_';
}
void Computermove(){
	
	while (1){
		int col, row;
		col = rand() % 3;
		row = rand() % 3;
		if (g_checkerboard[row][col] == ' '){
			g_checkerboard[row][col] = 'x';
			break;
		}
		continue;
	}
}
int main(){
	srand((unsigned int)time(0));
	char winner;
		//绘制棋盘
		//1.初始化数组
		Init();
		//2.绘制棋盘
		while (1){
			Print();
			//玩家落子
			Playermove();
			//判断是否赢了
			winner = Checkwinner();
			printf("canshu%c\n", winner);
			if (winner == 'o'){
				Print();
				printf("玩家赢了\n");
				break;
			}
			if (winner == '_'){
				printf("平局");
				break;
			}
			//电脑赢了
			Computermove();
			winner = Checkwinner();
			printf("canshu%c\n", winner);
			if (winner =='x'){
				Print();
				printf("电脑获得胜利\n");
				break;
			}
			if (winner == '_'){
				printf("平局");
				break;
			}
		}
}