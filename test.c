#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAXROW 10
#define MAXCOL 10
#define MINE_COUNT 10
int menu(){
	printf("------------------\n");
	printf("����0������Ϸ\n");
	printf("����1��ʼ��Ϸ\n");
	printf("------------------\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
void init(char showmap[MAXROW + 2][MAXCOL + 2],
	char minemap[MAXROW + 2][MAXCOL + 2]){
	//��ʼ��showmap��
	for (int row = 0; row < MAXROW+2; ++row){
		for (int col=0;col<MAXCOL+2 ;++col){
			showmap[row][col] = '*';
		}
	}
	//��ʼ��minemap
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
	//����һ����Ϸ
	//��Ҫ������ά�����ʾ��ͼ
	//��һ�������ʾ��ͼ
	//����showmap���λ��û���ƿ���*��ʾ
	//����ƿ���һ����������ֱ�ʾ
	char showmap[MAXROW + 2][MAXCOL + 2];
	//�ڶ��������ʾ����
	//mainemap��ߵ�Ԫ�������¼������
	//����Ϊ1û����0
	char minemap[MAXROW + 2][MAXCOL + 2];
	//��ʼ������
	init(showmap,minemap);
	//��ӡ����ͼ
	displaymap(showmap);
	while (1){
		//�����������,�ж������Ƿ�Ϸ�
		int row, col,count_remove=0;
		printf("����������(x y)\n");
		scanf("%d %d", &row, &col);
		if (row > MAXROW || row<=0 || col>MAXCOL || col <= 0){
			printf("��������ٴ�����:\n");
				continue;
		}
		//�ж�����Ƿ����
		//1.������Ϸ����
		if (minemap[row][col] == '1'){
			displaymap(minemap);
			printf("������Ϸ\n");
			break;
		}
		++count_remove;
		//�ǲ����ƿ������еĸ���
		if(count_remove==MAXROW*MAXCOL-MINE_COUNT){
			displaymap(minemap);
			printf("��ϲ��ʤ\n");
			break;
		}
		//���û����ͳ�Ƹ�λ����Χ�м����׸��µ�ͼ
			updatemap(minemap,showmap,row,col);
			displaymap(showmap);
	}
}
void Start(){
	while (1){
		int choice = menu();
		if (choice == 0){
			printf("�˳���Ϸ\n");
			break;
		}
		else
			Game();
	}
}
int main(){
	//1.չʾһ����Ϸ�˵�
	Start();
}