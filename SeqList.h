#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
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
	//2.������Ҫ�������ռ����,���ڸ�����û������;
	assert(pSeq != NULL);//ǰ�ö��Գ���ִ�е�����,ĩβ�����������������
	pSeq->size = 0;
	//memset(pSeq, 0, MAX_SIZE * sizeof(DataType));
}

void SeqListDestory(SeqList *pSeq) {
	assert(pSeq );
	pSeq->size = 0;
}
//��
//β��
void SeqListPushBack(SeqList *pSeq, DataType date) {
	assert(pSeq);
	//����
	if (pSeq->size >= MAX_SIZE) {
		assert(0);
		return;
	}
	//ͨ�����
	pSeq->array[pSeq->size] = date;
	date++;
}
//ͷ��
void SeqListPushHead(SeqList *pSeq, DataType date) {
	//�ƶ�λ��;
	//i��ʾλ��(�Ӻ���ǰ���ֹ����)
	for (int i = pSeq->size; i > 0; --i) {
		pSeq->array[i] = pSeq->array[i-1];
		//λ��                 ֵ
	}
	//����
	//��ֵ
	pSeq->array[0] = date;
	//����λ��
	pSeq->size++;
	//i��������i
	/*for (int i = pSeq->size - 1; i >= 0; --i) {
		pSeq->array[i+1]= pSeq->array[i];
	}*/
}
void SeqListInsert(SeqList* pSeq,int pos,DataType date) {
	//�������
	assert(pSeq);
	//����
	if (pSeq->size >= MAX_SIZE) {
		assert(0);
		return;
	}
	//�ƶ�λ��
	//1.�Ӻ���ǰ
	for (int i = pSeq->size; i >= pos; i--) {
		pSeq->array[i] = pSeq->array[i - 1];
	}
	/*for (int i = pSeq->size - 1; i >= pos - 1; --i) {
		pSeq->array[i + 1] = pSeq->array[i];
	}*/
	//��ֵ
	pSeq->array[pos-1] = date;
	//����λ��
	pSeq->size++;
}
//ɾ
//βɾ
void SeqListPushpro(SeqList *pSeq) {
	//ɾ����
	if (pSeq->size == 0) {
		assert(0);
		return;
	}
	assert(pSeq);
	pSeq->size--;
}
void SeqListPopFront(SeqList* pSeq) {
	if (pSeq->size == 0) {
		assert(0);
		return;
	}
	for (int i = 0; i < pSeq->size - 1; ++i) {
		pSeq->array[i] = pSeq->array[i+1];
	}
	pSeq->size--;
}
void SeqListErase(SeqList* pSeq, int pos) {
	//������
	if (pSeq->size == 0) {
		assert(0);
		return;
	}
	for (int i = pos; i < pSeq->size; ++i) {
		pSeq->array[i-1] = pSeq->array[i];
	}
	pSeq->size--;
}
//����
int SeqListfind(SeqList *pSeq,DataType to_find) {
	for (int i = 0; i < pSeq->size; ++i) {
		if (to_find == pSeq->array[i]) {
			return i;
		}
		return -1;
	}
}
//��������ɾ��;
void SeqListremove(SeqList *pSeq, DataType data) {
	int op = SeqListfind(pSeq, data);
	if (op == -1) {
		printf("û�ҵ�\n");
	}
	SeqListErase(pSeq, op);
}
void SeqListPrint(const SeqList *pSeq) {
	for (int i = 0; i < pSeq->size; ++i) {
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}
//ʹ�ó���
void Test() {
	//1.�������
	SeqList seqList;
	SeqListInit(&seqList);//�ı��ڲ�ֵ
	SeqListPushHead(&seqList, 1);
	SeqListPushHead(&seqList, 2);
	SeqListPushHead(&seqList, 3);
	SeqListPushHead(&seqList, 4);
	SeqListPushHead(&seqList, 5);
	SeqListPrint(&seqList);
	SeqListErase(&seqList, 4);
	SeqListPrint(&seqList);
	SeqListInsert(&seqList, 3, 7);
	SeqListPrint(&seqList);
}
