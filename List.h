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
static ListNode* CreatNode(DataType data) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->data = data;
	return newNode;
}
void ListNodePushFirst(ListNode** ppFirst, DataType data) {
	ListNode* newNode = CreatNode(data);
	newNode->next = *ppFirst; 
	*ppFirst = newNode;
}
void ListNodePushBack(ListNode** ppfirst,DataType data){
	//���β����ǿ�����
	if (*ppfirst == NULL) {
		ListNode *newNode;
		newNode = CreatNode(data);
		newNode->next = *ppfirst;
		*ppfirst = newNode;
	}
	ListNode *cur = *ppfirst;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	ListNode *newNode;
	newNode = CreatNode(data);
	newNode->next = NULL;
	cur->next = newNode;

}
//βɾ
//1.���ڵ������ڶ�ʱ�ҵ����ڶ������
//2.�������޷�ɾ��
//զ�ҵ����ڶ������
//�ж��ǲ��ǿ�����
//�ж��ǲ���ֻ��һ�����
void ListPopBack(ListNode **ppfirst) {
	assert(*ppfirst != NULL);
	ListNode* cur=*ppfirst;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		if ((*ppfirst)->next!=NULL) {
			free(cur->next);
			cur->next = NULL;
		}
		else {
			free(cur->next);
			*ppfirst = NULL;
		}
}
//����
ListNode *FindNode(ListNode* first,DataType to_find) {
	//����
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		if (to_find == cur->data) {
			return cur;
		}
		else
			return NULL;
	}
}
//���ǰ����
void  ListInsert(ListNode **ppfirst, ListNode *pos, DataType data) {
	//ͷ��
	if (*ppfirst == pos) {
		ListNodePushFirst(ppfirst, data);
		return;
	}
	//��pos��ǰһ�����
	ListNode *cur = *ppfirst;
	while (cur->next == pos) {
		cur = cur->next;
	}
	ListNode *newnode = CreatNode(data);
	newnode->next = cur->next;
	cur->next = newnode;
}
//ɾ��ָ�����