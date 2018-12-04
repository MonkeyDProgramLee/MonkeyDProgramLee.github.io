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
	//时间片
	double part_time;
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
	return NewNode;
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
	//输入预计运行时间
	double pre_time;
	printf("输入预计运行时间:");
	scanf("%lf", &pre_time);
	pcb->pre_time;
	//输入到达时间
	double arrive_time;
	printf("输入到达时间:");
	scanf("%lf", &arrive_time);
	pcb->arrive_time = arrive_time;
	//输入优先级
	int super;
	printf("输入优先级:");
	scanf("%d", &super);
	pcb->super=super;
	//输入时间片
	double part_time;
	printf("输入时间片:");
	scanf("%lf", &part_time);
	pcb->part_time = part_time;
}
void Print(PCBListNode* pFirst) {
	printf("内部标识符:%d\n", pFirst->PBCNode.order);
	printf("预计运行时间:%f\n", pFirst->PBCNode.pre_time);
	printf("到达时间:%f\n", pFirst->PBCNode.arrive_time);
	printf("优先级:%d\n", pFirst->PBCNode.super);
	printf("时间片:%f\n", pFirst->PBCNode.part_time);
	printf("开始时间:%lf\n", pFirst->PBCNode.start_time);
	printf("完成时:%d\n", pFirst->PBCNode.finsh_time);
	printf("周转时间:%lf\n", pFirst->PBCNode.zhouzhuan_time);
	printf("带权周转时间:%lf\n", pFirst->PBCNode.daiquanzhouzhuan_time);
	printf("平均周转时间:%lf\n", pFirst->PBCNode.pingjunzhouzhuan_time);
	printf("平均地权周转时间:%lf\n", pFirst->PBCNode.pingjundaiquanzhouzhuan_time);
}
void Swap(PCBListNode* front, PCBListNode* behind) {
	PCBListNode* NWE;
	front->next = NWE;
	front->next = behind->next;
	behind->next = NWE;
}
void SortByArrive_time(PCBListNode **ppFirst) {
	PCBListNode* cur = *ppFirst;
	while (cur != NULL) {
		if(cur->PBCNode.arrive_time<)
		cur = cur->next;
	}
}
void  Test() {
	PCB pcb;
	PCBListNode* ppFirst;
	Init(&ppFirst);
	Input(&pcb);
	PushNodeFront(&ppFirst, pcb);
	Print(ppFirst);

}