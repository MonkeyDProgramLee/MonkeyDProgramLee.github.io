#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//�����ǳ�������
//����
typedef int DataType;
#define MAX_SIZE 100

typedef struct SeqList {
	DataType array[MAX_SIZE];
	int size;//1.˳������Ѿ����˵����ݸ���;
			 //2.��ǰ�����±�
} SeqList;
//�ӿ�(����)
//��ʼ��/����
//��ɾ�Ĳ�
//��ʼ���ӿ�(�ӿ����)
void SeqListInit(SeqList *pSeq){
	//1.��ʼ�� size
	//2.������Ҫ�������ռ����
	assert(pSeq != NULL);
	pSeq->size = 0;
}
void SeqListDestory(SeqList *pSeq) {
	assert(pSeq != NULL);
	pSeq->size = 0;
}
//��
//β��
void SeqListPushBack(SeqList *pSeq, DataType date) {
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE) {
		assert(0);
		return;
	}
	pSeq->array[pSeq->size] = date;
	date++;
}
//ͷ��
void SeqListPushHead(SeqList *pSeq, DataType date) {
	for (int i = pSeq->size; i > 0; --i) {

	}
}
//ɾ
//βɾ
void SeqListPushpro(SeqList *pSeq) {
	
}
//ʹ�ó���
void Test() {
	//1.
	SeqList seqList;
	SeqListInit(&seqList);//�ı��ڲ�ֵ
}
