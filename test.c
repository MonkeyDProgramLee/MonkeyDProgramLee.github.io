#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXROW 9
#define MAXCOL 9
#define MINE_COUNT 10
int menu(){
	printf("------------------\n");
	printf("����0������Ϸ\n");
	printf("����0������Ϸ\n");
	printf("------------------\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
void init(char minemap[MAXROW + 2][MAXCOL + 2],
	char showmap[MAXROW + 2][MAXCOL + 2]){
	//��ʼ��showmap��
	for (int row = 0; row < MAXROW; ++row){
		for (int col=0;col<MAXCOL ;++col){
			showmap[row][col] = '*';
		}
	}
	//��ʼ��minemap
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
	//��ʼ������
	char minemap[MAXROW + 2][MAXCOL + 2];
	char showmap[MAXROW + 2][MAXCOL + 2];
	init(minemap[MAXROW + 2][MAXCOL + 2],
		showmap[MAXROW + 2][MAXCOL + 2]);
	//��ӡ��������
	
}
void Start(){
	while (1){
		int choice = menu();
		if (choice == 1){
			Game();
		}
		else
			printf("�˳���Ϸ\n");
	}
}
int main(){
	//1.չʾһ����Ϸ�˵�
	Start();
}