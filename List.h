#pragma once
#include<stdio.h>
#include<stdlib.h>
typedef struct PCB {
	//���̱�־��
	int order;
	//Ԥ������ʱ��
	double pre_time;
	//����ʱ��
	double arrive_time;
	//���ȼ�
	int super;
	//��ʼʱ��
	double start_time;
	//���ʱ��
	double finsh_time;
	//��תʱ��
	double zhouzhuan_time;
	//��Ȩ��תʱ��
	double daiquanzhouzhuan_time;
	//ƽ����תʱ��
	double pingjunzhouzhuan_time;
	//ƽ����Ȩ��תʱ��
	double pingjundaiquanzhouzhuan_time;
}PCB;
typedef struct PCBListNode {
	PCB PBCNode;
	struct PCBListNode* next;
}PCBListNode;
//��ʼ�����
void Init(PCBListNode **ppFirst) {
	*ppFirst = NULL;
}
//����һ�����
static PCBListNode* CreatPBCNode(PCB PBCNodedata) {
	//�����ռ�
	PCBListNode *NewNode = (PCBListNode*)malloc(sizeof(PCBListNode));
	NewNode->PBCNode = PBCNodedata;
}
//��
void PushNodeFront(PCBListNode **ppFirst , PCB PBCNodedata) {
	PCBListNode *NewNode = CreatPBCNode(PBCNodedata);
	NewNode->next=*ppFirst;
	*ppFirst = NewNode;
}
void Input(PCB *pcb) {
	//������̱�־��
	int order;
	printf("����������:");
		scanf("%d", &order);
	pcb->order = order;
}
void Print(PCBListNode* pFirst) {
	printf("�ڲ���ʶ��:%d\n", pFirst->PBCNode.order);
}
void  Test() {
	PCB pcb;
	PCBListNode* ppFirst;
	Init(&ppFirst);
	Input(&pcb);
	PushNodeFront(&ppFirst, pcb);
	Print(ppFirst);
}