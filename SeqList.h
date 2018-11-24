#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
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
	//2.可能需要把容器空间清空,对于该例子没有意义;
	assert(pSeq != NULL);//前置断言程序执行的条件,末尾置输出结果满足的条件
	pSeq->size = 0;
	//memset(pSeq, 0, MAX_SIZE * sizeof(DataType));
}

void SeqListDestory(SeqList *pSeq) {
	assert(pSeq );
	pSeq->size = 0;
}
//增
//尾插
void SeqListPushBack(SeqList *pSeq, DataType date) {
	assert(pSeq);
	//满了
	if (pSeq->size >= MAX_SIZE) {
		assert(0);
		return;
	}
	//通常情况
	pSeq->array[pSeq->size] = date;
	date++;
}
//头插
void SeqListPushHead(SeqList *pSeq, DataType date) {
	//移动位置;
	//i表示位置(从后往前搬防止覆盖)
	for (int i = pSeq->size; i > 0; --i) {
		pSeq->array[i] = pSeq->array[i-1];
		//位置                 值
	}
	//插入
	//赋值
	pSeq->array[0] = date;
	//更新位置
	pSeq->size++;
	//i代表数据i
	/*for (int i = pSeq->size - 1; i >= 0; --i) {
		pSeq->array[i+1]= pSeq->array[i];
	}*/
}
void SeqListInsert(SeqList* pSeq,int pos,DataType date) {
	//特殊情况
	assert(pSeq);
	//满了
	if (pSeq->size >= MAX_SIZE) {
		assert(0);
		return;
	}
	//移动位置
	//1.从后往前
	for (int i = pSeq->size; i >= pos; i--) {
		pSeq->array[i] = pSeq->array[i - 1];
	}
	/*for (int i = pSeq->size - 1; i >= pos - 1; --i) {
		pSeq->array[i + 1] = pSeq->array[i];
	}*/
	//赋值
	pSeq->array[pos-1] = date;
	//更新位置
	pSeq->size++;
}
//删
//尾删
void SeqListPushpro(SeqList *pSeq) {
	//删完了
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
	//搬完了
	if (pSeq->size == 0) {
		assert(0);
		return;
	}
	for (int i = pos; i < pSeq->size; ++i) {
		pSeq->array[i-1] = pSeq->array[i];
	}
	pSeq->size--;
}
//查找
int SeqListfind(SeqList *pSeq,DataType to_find) {
	for (int i = 0; i < pSeq->size; ++i) {
		if (to_find == pSeq->array[i]) {
			return i;
		}
		return -1;
	}
}
//根据数据删除;
void SeqListremove(SeqList *pSeq, DataType data) {
	int op = SeqListfind(pSeq, data);
	if (op == -1) {
		printf("没找到\n");
	}
	SeqListErase(pSeq, op);
}
void SeqListPrint(const SeqList *pSeq) {
	for (int i = 0; i < pSeq->size; ++i) {
		printf("%d ", pSeq->array[i]);
	}
	printf("\n");
}
//使用场景
void Test() {
	//1.定义变量
	SeqList seqList;
	SeqListInit(&seqList);//改变内部值
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
