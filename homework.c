#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<math.h>
#define ROW 10
#define COL 10
int Fibonacci(int i) {
	//项数小于0
	//项数小于三的情况
	if (i < 3) {
		return 1;
	}
	return Fibonacci(i - 1) + Fibonacci(i-2);
}
int UFib(int i) {
	if (i < 0) {
		printf("输入错误\n");
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
		printf("错误\n");
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
		printf("输入有误\n");
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
		printf("错误\n");
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
//编写一个函数 reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

void reverse_string(char * string) {
	assert(string != NULL);
	char* start = string;
	char* end = string+strlen(string) - 1;
	while (start<end) {
		char temp;
		temp = *start;
		*start = *end;
		*end = temp;
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
		//交换首尾内容
		char temp=*start;
		*start = *end;
		*end = '\0';
		Reverse_string(start + 1);
		//恢复数据
		*end = temp;
	}   
}
int GetoneCount(int number) {
	int count = 0;
	for (int i = 0; i <= 32; ++i) {
		if (number&(1 << i))
			count++;
	}
	return count;
}
int getonrcount(int num) {
	int count = 0;
	while (num ) {
		++count;		
		num = num & (num - 1);
	}
	return count;
}
void Getbit(int num) {
	for (int i = 31; i >0;i-=2) {
		printf("%d ", (num>>i) & 1);
	}
	printf("\n");
	for (int i = 30; i >=0; i-=2) {
		printf("%d ", (num >> i) & 1);
	}
}
void printfbit(int num) {
	if (num > 9) {
		printfbit( num / 10);
	}
	printf("%d ", num % 10);
}
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
int countDif(int x, int y) {
	int count=0;
	int i = 32;
	while (i >= 0) {
		if (((x >> i)&1) != ((y >> i)&1))
			count++;
		--i;
	}
	
	return count;
}
void Pre() {
	int a, b, c, d, e;
	for ( a = 1; a < 6; ++a) {
		for ( b = 1; b < 6; ++b) {
			for ( c = 1; c < 6; ++c) {
				for ( d = 1; d < 6; ++d) {
					for ( e = 1; e < 6; ++e) {
						if (((b == 2 && a != 3) || (b != 2 && a == 3)) &&
							((b == 2 && e != 4) || (b != 2 && e == 4)) &&
							((c == 1 && d != 2) || (c != 1 && d == 2)) &&
							((c == 5 && d != 3) || (c != 5 && d == 3)) &&
							((e == 4 && a != 1) || (e != 4 && a == 1)))
							if(a*b*c*d*e==120)
							printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
					}
				}
			}
		}
	}
}
void Killer() {
	char killer;
	for (killer = 'a'; killer <= 'd'; ++killer) {
		if (((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd')) == 3)
			printf("%c\n", killer);
	}
}
void PrintfYH() {
	int arr[ROW][COL];
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col <= row ; ++col) {
			if (row < 2||col==0||row == col) {
				arr[row][col] = 1;
			}
			else {
				arr[row][col] = arr[row - 1][col] + arr[row - 1][col - 1];
			}
			printf("%d  ", arr[row][col]);
		}
		printf("\n");
	}
}

unsigned int reverse_bit(unsigned int value) {
	unsigned int sum = 0;
	for (int i = 0; i < 32; ++i) {
		sum = sum + ((value >> i) & 1)*(unsigned int)pow(2, 31 - i);
	}
	return sum;
}
unsigned int reverse_bit2(unsigned int value) {
	unsigned int temp = 0;
	for (int i = 0; i < 32; ++i) {
		//为了保存获取到的值所以才挪动
		temp = temp << 1;
		//把第i位的值放在temp的最后一位
		temp = temp | ((value >> i) & 1);
	}
	return temp;
}
int avrrage(int x,int y) {
	int sum = x + y;
	return sum >> 1;
	//return x&y+(x^y)>>1;
}
int Differ(int val[],int len) {
	int ret = 0;
	for (int i = 0; i < len; ++i) {
		ret = ret ^ val[i];
	}
	return ret;
}
void Change(char* arr[]) {
	Reverse_string(arr);
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
	//char str[] = {0};
	//scanf("%s", str);
   // int ret = m_strlen(str);
    //printf("%d\n", ret);
	//Reverse_string(str);
	//printf("%s\n", str);
	//Getbit(128);
	//printfbit(5236);
	//printf("%d\n", GetoneCount(6));
	/*Pre();
	Killer();
	printf("%d\n", countDif(1999, 2299));
	PrintfYH();*/
	//
	printf("%u\n",reverse_bit2(25));
	system("pause");
	return 0;
}