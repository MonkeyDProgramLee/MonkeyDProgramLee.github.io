#pragma once
#define CAPACITY_INIT 30
#include<stdlib.h>
typedef int DataType;
typedef struct SeqListD {
	DataType* prray;
	int capacity;//��ǰ����=>MAXSIZE
	int size;
}SeqListD;
//��ʼ��/����/β��
void SeqListDInit(SeqListD *pSeq) {
	pSeq->size = 0;
	//��������ռ�;
	pSeq->capacity = CAPACITY_INIT;
	pSeq->prray = (DataType *)malloc(sizeof(DataType)*pSeq->capacity);
}
static void ExpandIfRequired(SeqListD* pSeq) {
	if (pSeq->size < pSeq->capacity) {
		return;
	}
	//�����µķ���
	pSeq->capacity += 10;
	DataType* newprry = (DataType*)malloc(sizeof(DataType)*pSeq->capacity);
	//����ԭ��������������
	for (int i = 0; i < pSeq->size; ++i) {
		newprry[i] = pSeq->prray[i];
	}
	//�˷���
	free(pSeq->prray);
	//���·�
	pSeq->prray = newprry;
}
void SeqListPushBack(SeqListD* pSeq,DataType data) {
	//��û��Խ����û��ֱ�Ӳ���;
	ExpandIfRequired(pSeq);
	pSeq->prray[pSeq->size] = data;
	pSeq->size++;
}
void Test() {
	SeqListD* pSeq;
}