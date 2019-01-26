#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<windows.h>
#include<math.h>
#define ROW 3
#define COL 3
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
void reseve(char* str) {
	/*char* start = str;
	char* end = str + strlen(str)-1;
	if (*str) {
		char temp;
		temp = *start;
		*start = *end;
		*end = '\0';
		reseve(start + 1);
		*end=temp;
	}*/
	char* start = str;
	char* end = str + Strlen(str) - 1;
	if (*str) {
		//交换首尾内容
		char temp = *start;
		*start = *end;
		*end = '\0';
		Reverse_string(start + 1);
		//恢复数据
		*end = temp;
	}
	  
}
void part_change(char* str, char* end) {
	while (str < end) {
		char temp;
		temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
}
void Change(char* str) {
  //整体交换
	reseve(str);
	//局部交换
	char* start = str;
	char* cur = str;
	while (*cur) {
		cur++;
		if (*cur == ' ' || *cur == '\0') 
		{
			part_change(start, cur-1);
			start = cur + 1;
          }
	}
}
void swp(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void SortByS(int arr[],int size) {
	for (int left = 0; left < size; ++left) {
		if (arr[left] % 2 == 0) {
			for (int right = size-1; right >= 0; --right) {
				if (arr[right] % 2 != 0&&left<right) {
					int temp;
					temp = arr[right];
					arr[right] = arr[left];
					arr[left] = temp;
				}
			}
		}
	}
}
int Find_Num(int arr[3][3],int to_find,int row ,int col) {
	if (to_find<arr[0][0] || to_find>arr[ROW - 1][COL - 1]){
		printf("没有要找的数\n");
		return -1;
		}
	int r = 0, c = COL-1;
	while (r <= ROW - 1 && c >= 0) {
		if (to_find < arr[r][c]) {
			c--;
		}
		if (to_find > arr[r][c]) {
			r++;
		}
		if (to_find == arr[r][c]) {
			return 1;
		}
		if (r <= ROW - 1 && c >= 0)
			return -1;
	}
}
void left_rotate(char* str , int k) {
	char temp = *str;
	char* cur = str;
	while (k--) {
		while (*(cur + 1)) {
			*cur = *(cur + 1);
			cur++;
		}
		*cur = temp;
	}
}
void nizhuanstring(char* left, char* right) {
	while (left < right) {
		char temp;
		temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void left_rotate2(char* str, int k) {
	nizhuanstring(str, str + k-1);
	nizhuanstring(str + k, str + strlen(str) - 1);
	nizhuanstring(str, str + strlen(str) - 1);
}
void right_ratate(char* str, int k) {
	left_rotate(str, strlen(str) - k);
}
void paunduan(char* dest,char* src) {
	int len = strlen(src);
	for (int i = 0; i < len; ++i) {
		eft_rotate(src, i);
		if (strcmp(dest, src) == 0) {
			prinft("找到了\n");
			break;
		}
		if (i == len - 1) {
			printf("\n");
		}
	}
}

int main() {
	//int arr[3][3] = { 1,2,3,2 ,3,4,3,4,5};
	//int ret = Find_Num(arr, 4, 3, 3);
	//printf("%d\n", ret);
	//SortByS(arr, 8);
	//for (int i = 0; i <8; ++i) {
	//	printf("%d\n", arr[i]);
	//}
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
	//gets(str);
	//char* str = "abcd";
	//reseve(str);
	//Change(str);
   // int ret = m_strlen(str);
    //printf("%d\n", ret);
	//Reverse_string(str);
	// left_rotate(str , 1);
	//printf("%s\n", str);
	//Getbit(128);
	//printfbit(5236);
	//printf("%d\n", GetoneCount(6));
	/*Pre();
	Killer();
	printf("%d\n", countDif(1999, 2299));
	PrintfYH();*/
	//
	//printf("%u\n",reverse_bit2(25));
	int pos = -1;
	int arr[] = { 1,1,2,2,3,3,5,7 };
	int ret = 0;
	int x1=0;
	int x2=0;
	for (int i = 0; i < sizeof(arr); ++i) {
		ret = ret ^ arr[i];
	}
	for (int i = 0; i < 32; ++i) {
		if ((ret >> i) & 1 == 1) {
			pos = i;
			break;
		}
	}
	for (int i = 0; i < sizeof(arr); ++i) {
		if ((arr[i] >> pos) & 1 == 1) {
			x1 = x1 ^ arr[i];
		}
		else {
			x2 = x2 ^ arr[i];
		}
		int total = 0;
		int money = 20;
		int empty = 20;
		while (empty > 1) {
			total = money + empty/2;
			empty = empty / 2+empty%2;

		}
	system("pause");
	return 0;
}