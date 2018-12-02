#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct PCB {
	//进程标志符
	int order;
	//预计运行时间
	double pre_time;
	//到达时间
	double arrive_time;
	//优先级
	int super;
	//开始时间
	double start_time;
	//完成时间
	double finsh_time;
	//周转时间
	double zhouzhuan_time;
	//带权周转时间
	double daiquanzhouzhuan_time;
	//平均周转时间
	double pingjunzhouzhuan_time;
	//平均带权周转时间
	double pingjundaiquanzhouzhuan_time;
}PCB;
typedef struct PCBListNode {
	PCB PBCNode;
	struct PCBListNode* next;
}PCBListNode;
//初始化结点
void Init(PCBListNode **ppFirst) {
	*ppFirst = NULL;
}
//开创一个结点
static PCBListNode* CreatPBCNode(PCB PBCNodedata) {
	//开创空间
	PCBListNode *NewNode = (PCBListNode*)malloc(sizeof(PCBListNode));
	NewNode->PBCNode = PBCNodedata;
}
//增
void PushNodeFront(PCBListNode **ppFirst , PCB PBCNodedata) {
	PCBListNode *NewNode = CreatPBCNode(PBCNodedata);
	NewNode->next=*ppFirst;
	*ppFirst = NewNode;
}
void Input(PCB *pcb) {
	//输入进程标志符
	int order;
	printf("输入进程序号:");
		scanf("%d", &order);
	pcb->order = order;
}
void Print(PCBListNode* pFirst) {
	printf("内部标识符:%d\n", pFirst->PBCNode.order);
}
void  Test() {
	PCB pcb;
	PCBListNode* ppFirst;
	Init(&ppFirst);
	Input(&pcb);
	PushNodeFront(&ppFirst, pcb);
	Print(ppFirst);
}