#pragma once
#define CAPACITY_INIT 30
#include<stdlib.h>
typedef int DataType;
typedef struct SeqListD {
	DataType* prray;
	int capacity;//当前容量=>MAXSIZE
	int size;
}SeqListD;
//初始化/销毁/尾插
void SeqListDInit(SeqListD *pSeq) {
	pSeq->size = 0;
	//获得容器空间;
	pSeq->capacity = CAPACITY_INIT;
	pSeq->prray = (DataType *)malloc(sizeof(DataType)*pSeq->capacity);
}
static void ExpandIfRequired(SeqListD* pSeq) {
	if (pSeq->size < pSeq->capacity) {
		return;
	}
	//申请新的房间
	pSeq->capacity += 10;
	DataType* newprry = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	//告诉原来的数据来这里
	for (int i = 0; i < pSeq->size; ++i) {
		newprry[i] = pSeq->prray[i];
	}
	//退房子
	free(pSeq->prray);
	//进新房
	pSeq->prray = newprry;
}
void SeqListPushBack(SeqListD* pSeq,DataType data) {
	//有没有越界若没有直接插入;
	ExpandIfRequired(pSeq);
	pSeq->prray[pSeq->size] = data;
	pSeq->size++;
}
void Test() {
	SeqListD* pSeq;
}