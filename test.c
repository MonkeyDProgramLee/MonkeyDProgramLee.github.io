//玩家落子判断游戏是否结束
//电脑落子判断游戏是否结束
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
				g_checkerboard[row][col] = 'o';
			}
		}
	}
void Print(){
	for (int row = 0; row < ROW; ++row){
		if (row == 0){
			printf(" -----------\n");
		}
		printf("| %c | %c | %c |\n", g_checkerboard[row][0], g_checkerboard[row][1],
			g_checkerboard[row][2]);
		printf(" -----------\n");
	}
}
void Playermove(){
	int row, col;
	while (1){
		printf("请输入下子的坐标：\n");
		scanf("%d,%d", &row, &col);
		g_checkerboard[row][col]='o';
		if (row<0 || row>3 || col<0 || col>3||g_checkerboard[row][col]!=' '){
			printf("输入有误请再次输入");
			continue;
		}
		break;
	}
}
void Computermove(){
	int col, row;
	srand((unsigned int)time(0));
	while (1)
	{
		col = rand() % 3;
		row = rand() % 3;
		g_checkerboard[row][col] = 'x';
		if (row<0 || row>3 || col<0 || col>3 || g_checkerboard[row][col] != ' '){
			printf("输入有误请再次输入");
			continue;
		}
	}
}
char Checkwinner(){
	//如果对角线行列值都为o则判plyer为赢
	int col, row,count=0;
	//1.判断行
	for (row = 0; row < ROW; ++row){
		if (g_checkerboard[row][0] = 'o' == g_checkerboard[row][1] ==
			g_checkerboard[row][2])
			return 'o';
	}
	//2.判断列
	for (col = 0; col < COL; ++col){
		if (g_checkerboard[0][col] = 'o' == g_checkerboard[1][col] ==
			g_checkerboard[2][col])
			return 'o';
	}
		//3.对角线
		if (g_checkerboard[0][0] == g_checkerboard[1][1] == 
			g_checkerboard[2][2]=='o'|| 
			g_checkerboard[0][2] ==g_checkerboard[1][1] == 
			g_checkerboard[2][0]=='o')
			return 'o';
			//computer
			for (row = 0; row < ROW; ++row){
				if (g_checkerboard[row][0] = 'x' == g_checkerboard[row][1] ==
					g_checkerboard[row][2])
					return 'o';
			}
			for (col = 0; col < COL; ++col){
				if (g_checkerboard[0][col] = 'x' == g_checkerboard[1][col] ==
					g_checkerboard[2][col])
					return 'o';
			}
				if (g_checkerboard[0][0] == g_checkerboard[1][1] ==
					g_checkerboard[2][2] == 'x' ||
					g_checkerboard[0][2] == g_checkerboard[1][1] ==
					g_checkerboard[2][0] == 'x'){
					return 'o';
					for (row = 0; row < ROW; ++row){
						for (col = 0; col < COL; ++col){
							if (g_checkerboard[row][col] == ' ')
								count++;
						}
						if (count == 0)
							return '_';

					}
				

					int main() {
						Init();
						Print();
						char winner;
						while (1){
							Playermove();
							winner = Checkwinner();
							if (winner = 'x'){
								printf("玩家胜利");
								break;
							}
							else if (winner == 'o'){
								printf("电脑胜利");
								break;
							}
							else if (winner == ' ')
							{
								printf("平局");
							}
							Computermove();
							if (winner = 'x'){
								printf("玩家胜利");
								break;
							}
							else if ( winner == 'o'){
								printf("电脑胜利");
								break;
							}
							else if (winner == ' ')
							{
								printf("平局");
							}
						}
					}
			