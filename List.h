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
	//ʱ��Ƭ
	double part_time;
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
	return NewNode;
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
	//����Ԥ������ʱ��
	double pre_time;
	printf("����Ԥ������ʱ��:");
	scanf("%lf", &pre_time);
	pcb->pre_time;
	//���뵽��ʱ��
	double arrive_time;
	printf("���뵽��ʱ��:");
	scanf("%lf", &arrive_time);
	pcb->arrive_time = arrive_time;
	//�������ȼ�
	int super;
	printf("�������ȼ�:");
	scanf("%d", &super);
	pcb->super=super;
	//����ʱ��Ƭ
	double part_time;
	printf("����ʱ��Ƭ:");
	scanf("%lf", &part_time);
	pcb->part_time = part_time;
}
void Print(PCBListNode* pFirst) {
	printf("�ڲ���ʶ��:%d\n", pFirst->PBCNode.order);
	printf("Ԥ������ʱ��:%f\n", pFirst->PBCNode.pre_time);
	printf("����ʱ��:%f\n", pFirst->PBCNode.arrive_time);
	printf("���ȼ�:%d\n", pFirst->PBCNode.super);
	printf("ʱ��Ƭ:%f\n", pFirst->PBCNode.part_time);
	printf("��ʼʱ��:%lf\n", pFirst->PBCNode.start_time);
	printf("���ʱ:%d\n", pFirst->PBCNode.finsh_time);
	printf("��תʱ��:%lf\n", pFirst->PBCNode.zhouzhuan_time);
	printf("��Ȩ��תʱ��:%lf\n", pFirst->PBCNode.daiquanzhouzhuan_time);
	printf("ƽ����תʱ��:%lf\n", pFirst->PBCNode.pingjunzhouzhuan_time);
	printf("ƽ����Ȩ��תʱ��:%lf\n", pFirst->PBCNode.pingjundaiquanzhouzhuan_time);
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