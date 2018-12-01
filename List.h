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
	//如果尾插的是空链表
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
//尾删
//1.当节点数大于二时找倒数第二个结点
//2.空链表无法删除
//咋找倒数第二个结点
//判断是不是空链表
//判断是不是只有一个结点
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
//查找
ListNode *FindNode(ListNode* first,DataType to_find) {
	//遍历
	for (ListNode *cur = first; cur != NULL; cur = cur->next) {
		if (to_find == cur->data) {
			return cur;
		}
		else
			return NULL;
	}
}
//结点前插入
void  ListInsert(ListNode **ppfirst, ListNode *pos, DataType data) {
	//头插
	if (*ppfirst == pos) {
		ListNodePushFirst(ppfirst, data);
		return;
	}
	//找pos的前一个结点
	ListNode *cur = *ppfirst;
	while (cur->next == pos) {
		cur = cur->next;
	}
	ListNode *newnode = CreatNode(data);
	newnode->next = cur->next;
	cur->next = newnode;
}
//删除指定结点