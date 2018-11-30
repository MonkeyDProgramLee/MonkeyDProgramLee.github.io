#pragma once
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct ListNode {
	DataType data;
	struct ListNode* next;
}ListNode;
//��ʼ��
//Ŀ�������������Ϊ���������ͷָ�� Ҫ�޸�����ֵΪNULL ������Ҫͷ���ĵ�ַָ��ĵ�ַ���Դ������ָ��
void Init(ListNode **ppFirst) {
	assert(ppFirst != NULL);
	*ppFirst = NULL;
}
void ListNodePushFirst(ListNode** ppFirst, DataType data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data= data;
	newNode->next = *ppFirst;
	*ppFirst = newNode;
}
void ListNodePushBack(ListNode** ppfirst,DataType data){
	//���β����ǿ�����
	if (*ppfirst == NULL) {
		ListNode *newNode;
		newNode = (ListNode*)malloc(sizeof(ListNode));
		newNode->data = data;
		newNode->next = *ppfirst;
		*ppfirst = newNode;
	}
	ListNode *cur = *ppfirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	ListNode *newNode;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	newNode->next = NULL;
	cur->next = newNode;

}
