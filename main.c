#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//ʵ�ֵĹ���
//��
//ɾ
//��
//��
//��̬����ռ�
 //����һ�����ݴ�СΪ5��
//������������
typedef struct PersonInfo{
	char name[1024];
	char phone[1024];
} PersonInfo;
typedef struct AddressBook{
	PersonInfo* info;
	int capcity;//�����ڴ�ռ��С�ĳ�ʼֵ
	int size;
} AddressBook;
void Init(AddressBook* addr_book) {
	assert(addr_book != NULL);
	//����һ����СΪ5������ռ�
	addr_book->capcity = 5;
	addr_book->info = (PersonInfo*)malloc(addr_book->capcity * sizeof(PersonInfo));
	addr_book->size = 0;
}
void Realloc(AddressBook* addr_book) {
	//���鴫�������ݺϷ���
	assert(addr_book != NULL);
	//�����µĿռ�
	PersonInfo* old_info = addr_book->info;
	addr_book->capcity *= 2;
	addr_book->info = realloc(addr_book, addr_book->capcity);
	//��ԭ����������ݷŵ��µĿռ���
	for (int i = 0; i < addr_book->size; ++i) {
		addr_book->info[i] = old_info[i];
	}
	//�ͷ�ԭ�����ٵĿռ�
	free(addr_book->info);
}
void AddPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	//�ж��Ƿ���Ҫ�����µĿռ�
	if (addr_book->size > addr_book->capcity) {
		Realloc(addr_book);
	}
	PersonInfo* p = &addr_book->info[addr_book->size];
	printf("����������\n");
	scanf("%s", p->name);
	printf("������绰����\n");
	scanf("%s", p->phone);
	addr_book->size++;
}
void DelPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	printf("������ҪҪ�޸ĵ�����\n");
	int index;
	scanf("%d", &index);
	//�������ݺϷ���
	if (index > addr_book->size) {
		printf("�����������������\n");
		return;
	}
	printf("ȷ��ɾ��������Y:\n");
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
	printf("����ʾ����%d����Ϣ\n",i);
}
void ModifyPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	printf("������Ҫ����Ҫ�޸ĵ���\n");
	int choice;
	scanf("%d", &choice);
	printf("ȷ���޸ĵ�ǰ��������Y:\n");
	char cmd[1024];
	scanf("%s", cmd);
	if (strcmp(cmd, "Y") == 0) {
		PersonInfo* p = &addr_book->info[choice];
		printf("�޸���ϵ������\n");
		scanf("%s", p->name);
		printf("�޸���ϵ�˵绰\n");
		scanf("%s", p->phone);
	}
}
void FindPersonInfo(AddressBook* addr_book) {
	assert(addr_book != NULL);
	printf("������Ҫ���ҵ���\n");
	int choice;
	scanf("%d", &choice);
	if (choice > addr_book->size) {
		printf("�������\n");
		return;
	}
	PersonInfo* p = &addr_book->info[choice];
	for (int i = 0; i < addr_book->size; ++i) {
		if (i == choice) {
			printf("[%d]\t%s\t%s\t\n", i, p->name, p->phone);
			return;
		}
	}
	printf("û�ҵ�\n");
}
int Menu() {
	printf("======================\n");
	printf("1.������ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.�޸���ϵ��\n");
	printf("4.������ϵ��\n");
	printf("5.��ʾ��ϵ��\n");
	printf("0.�˳�\n");
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
			printf("�������\n");
		}
		table[choice - 1](&addr_book);
	}
	system("pause");
	return 0;
}
