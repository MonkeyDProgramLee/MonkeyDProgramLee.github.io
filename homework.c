#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
int Fibonacci(int i) {
	//����С��0
	//����С���������
	if (i < 3) {
		return 1;
	}
	return Fibonacci(i - 1) + Fibonacci(i-2);
}
int UFib(int i) {
	if (i < 0) {
		printf("�������\n");
	}
	if (i < 3) {
		return 1;
	}
	int now = 0;
	int pre = 1;
	int pre_p = 1;
	while (i > 2)
	{
		now = pre + pre_p;
		pre_p = pre;
		pre = now;
		  --i;
	}
	return now ;
}
int Power(int n, int k) {
	if (n < 0) {
		printf("����\n");
	}
	if (k == 0) {
		return 1;
	}
	if (k == 0 && n > 0) {
		return 1;
	}
	if (n > 0 && k == 1) {
		return n;
	}
	return Power(n, k - 1)*n;
}
int DigitSum(int number) {
	int sum = 0;
	if (number < 0) {
		printf("��������\n");
	}
	int i = number / 10;
	if (i != 0) {
		sum=DigitSum(i)+sum;
	}
	//printf("%d\n", number % 10);
	sum = sum + number % 10;
	return sum;
}
int Factorial(int n) {
	if (n == 0) {
		printf("����\n");
	}
	if (n == 1) {
		return 1;
	}
	return Factorial(n - 1)*n;
}
int factorial(int n) {
	int ret = 1;
	while (n > 1) {
		ret *= n;
		--n;
	}
	return ret;
}
void GetBit(int i) {
	int m;
	m = i / 10;
	if (m > 0) {
		GetBit(m);
	}
	printf("%d\n",i%10);
}
//��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
void reverse_string(char * string) {
	assert(string != NULL);
	char* start = string;
	char* end = string+strlen(string) - 1;
	while (start<end) {
		char* temp=0;
		*temp = *start;
		*start = *end;
		*end = *temp;
		++start;
		--end;
	}
}
int Strlen(char* str) {
	int count = 0;
	while (*str) {
		count++;
		str++;
	}
	return count;
}
int m_strlen(char* str) {
	if (*str)
		return m_strlen(str + 1) + 1;
	else
	{
		return 0;
	}
}
void Reverse_string(char * str) {
	char* start = str;
	char* end = str + Strlen(str)-1;
	if (*str) {
		//������β����
		char temp=*start;
		*start = *end;
		*end = '\0';
		Reverse_string(start + 1);
		//�ָ�����
		*end = temp;
	}   
}
int main() {
	/*int ret2 = fibonacci(1);
	int ret3 = fibonacci(4);
	int ret4 = ufib(1);
	int ret5 = ufib(4);*/
	//int ret6 = Power(2, 0);
	//int ret6 = factorial(3);
	//GetBit(564);
	/*printf("%d\n", ret2);
	printf("%d\n", ret3);
	printf("%d\n", ret4);
	printf("%d\n", ret5);*/
	//printf("%d\n", ret6);
	char str[] = {0};
	scanf("%s", str);
   // int ret = m_strlen(str);
    //printf("%d\n", ret);
	Reverse_string(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}