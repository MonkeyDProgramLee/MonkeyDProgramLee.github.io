#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//数据是抽象类型
//数据
typedef int DataType;
#define MAX_SIZE 100

typedef struct SeqList {
	DataType array[MAX_SIZE];
	int size;//1.顺序表里已经存了的数据个数;
			 //2.当前可用下标
} SeqList;
//接口(函数)
//初始化/销毁
//增删改查
//初始化接口(接口设计)
void SeqListInit(SeqList *pSeq){
	//1.初始化 size
	//2.可能需要把容器空间清空
	assert(pSeq != NULL);
	pSeq->size = 0;
}
void SeqListDestory(SeqList *pSeq) {
	assert(pSeq != NULL);
	pSeq->size = 0;
}
//增
//尾插
void SeqListPushBack(SeqList *pSeq, DataType date) {
	assert(pSeq);
	if (pSeq->size >= MAX_SIZE) {
		assert(0);
		return;
	}
	pSeq->array[pSeq->size] = date;
	date++;
}
//头插
void SeqListPushHead(SeqList *pSeq, DataType date) {
	for (int i = pSeq->size; i > 0; --i) {

	}
}
//删
//尾删
void SeqListPushpro(SeqList *pSeq) {
	
}
//使用场景
void Test() {
	//1.
	SeqList seqList;
	SeqListInit(&seqList);//改变内部值
}
