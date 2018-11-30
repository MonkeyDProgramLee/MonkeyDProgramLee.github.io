#pragma once
#include<stdlib.h>
#include<assert.h>
typedef int DataType;
typedef struct ListNode {
	DataType data;
	struct ListNode* next;
}ListNode;
//初始化
//目的是让这个链表为空链表操作头指针 要修改他的值为NULL 所以需要头结点的地址指针的地址所以传入二级指针
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
	//如果尾插的是空链表
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
