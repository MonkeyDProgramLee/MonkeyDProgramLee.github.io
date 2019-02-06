#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//实现的功能
//增
//删
//改
//查
//动态分配空间
 //开辟一个数据大小为5的
//抽象数据类型
typedef struct PersonInfo{
	char name[1024];
	char phone[1024];
} PersonInfo;
typedef struct AddressBook{
	PersonInfo* info;
	int capcity;//开辟内存空间大小的初始值
	int size;
} AddressBook;
void Init(AddressBook* addr_book) {
	assert(addr_book != NULL);
	//开辟一个大小为5的数组空间
	addr_book->capcity = 5;
	addr_book->info = (PersonInfo*)malloc(addr_book->capcity * sizeof(PersonInfo));
	addr_book->size = 0;
}
void Realloc(AddressBook* addr_book) {
	//检验传入如数据合法性
	assert(addr_book != NULL);
	//开辟新的空间
	PersonInfo* old_info = addr_book->info;
	addr_book->capcity *= 2;
	addr_book->info = realloc(addr_book, addr_book->capcity);
	//将原来储存的数据放到新的空间中
	for (int i = 0; i < addr_book->size; ++i) {
		addr_book->info[i] = old_info[i];
	}
	//释放原来开辟的空间
	free(addr_book->info);
}
void AddPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	//判断是否需要开辟新的空间
	if (addr_book->size > addr_book->capcity) {
		Realloc(addr_book);
	}
	PersonInfo* p = &addr_book->info[addr_book->size];
	printf("请输入姓名\n");
	scanf("%s", p->name);
	printf("请输入电话号码\n");
	scanf("%s", p->phone);
	addr_book->size++;
}
void DelPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	printf("请输入要要修改的项数\n");
	int index;
	scanf("%d", &index);
	//检验数据合法性
	if (index > addr_book->size) {
		printf("输入错误请重新输入\n");
		return;
	}
	printf("确认删除请输入Y:\n");
	char cmd[1024];
	scanf("%s", cmd);
	if (strcmp(cmd, "Y") == 0){
		PersonInfo* from = &addr_book->info[index];
			PersonInfo* to = &addr_book->info[addr_book->size];
			*from = *to;
			addr_book->size--;
	}
	return;
}
void PrintfAllInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	int i = 0;
	PersonInfo* p = &addr_book->info[i];
	for (; i < addr_book->size; ++i) {
		printf("[%d]\t%s\t%s\t\n", i, p->name, p->phone);
	}
	printf("以显示以上%d条信息\n",i);
}
void ModifyPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	printf("请输入要输入要修改的项\n");
	int choice;
	scanf("%d", &choice);
	printf("确认修改当前项请输入Y:\n");
	char cmd[1024];
	scanf("%s", cmd);
	if (strcmp(cmd, "Y") == 0) {
		PersonInfo* p = &addr_book->info[choice];
		printf("修改联系人姓名\n");
		scanf("%s", p->name);
		printf("修改联系人电话\n");
		scanf("%s", p->phone);
	}
}
void FindPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	printf("请输入要查找的项\n");
	int choice;
	scanf("%d", &choice);
	if (choice > addr_book->size) {
		printf("输入错误\n");
		return;
	}
	PersonInfo* p = &addr_book->info[choice];
	for (int i = 0; i < addr_book->size; ++i) {
		if (i == choice) {
			printf("[%d]\t%s\t%s\t\n", i, p->name, p->phone);
			return;
		}
	}
	printf("没找到\n");
}
int Menu() {
	printf("======================\n");
	printf("1.增加联系人\n");
	printf("2.删除联系人\n");
	printf("3.修改联系人\n");
	printf("4.查找联系人\n");
	printf("5.显示联系人\n");
	printf("0.退出\n");
	printf("======================\n");
	int choice;
	scanf("%d", &choice);
	return choice;
}
int main() {
	AddressBook addr_book;
	Init(&addr_book);
	typedef void(*p_func)(AddressBook*);
	p_func table[5] = {
		AddPersonInfo,
		DelPersonInfo,
		ModifyPersonInfo,
		FindPersonInfo,	
		PrintfAllInfo
	};
	while (1)
	{
		int choice = Menu();
		if (choice == 0) {
			printf("GOODBYE\n");
			break;
	}
		if (choice < 0 && choice>5) {
			printf("输入错误\n");
		}
		table[choice - 1](&addr_book);
	}
	system("pause");
	return 0;
}
