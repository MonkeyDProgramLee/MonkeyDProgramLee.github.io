#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdint.h>
#include<string.h>
//int IsLittleEnd() {
//	int a = 0x11223344;
//	char* b = (char*)&a;
//	if (*b == 0x11) {
//		//ȡ����λ
//		return 0;
//	}
//		return -1;
//}
//int Add(int x, int y) {
//	return x + y;
//}
//int Sub(int x, int y) {
//	return x - y;
//}
//int Mul(int x, int y) {
//	return x * y;
//}
//int Div(int x, int y) {
//	return x / y;
//}
////int Menu() {
////	int choice;
////	return choice;
////}
//void Swp(int* x, int* y) {
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}
////����������һ������ָ�������������
//typedef int(*T)(int x,int y);
//void BubbleSort(int arr[],int size,T cmp) {
//	int bound;
//	for (bound = size; bound > 0; --bound) {
//		for (int i = 0; i < bound; ++i) {
//			if (cmp(arr[i], arr[i + 1])==0) {
//				Swp(&arr[i], &arr[i + 1]);
//			}
//		}
//	}
//}
////LessΪ�ص�����
//int Less(int x, int y) {
//	return x < y ? 1 : 0;
//}
//int Greater(int x, int y) {
//	return x > y ? 1 : 0;
//}
//int AbsLess(int x, int y) {
//	return
//}
size_t Strlen(const char* str) {
	//����Ϸ���
	assert(str != NULL);
	size_t count = 0;
	while (str[count] != '\0') {
		count++;
	}
	return count;
}
char* str(char* dest, const* src) {
	assert(dest != NULL);
	assert(src != NULL);
		int64_t i = 0;
	for (; src[i] != '\0'; ++i) {
		dest[i] = src[i];
}
	dest[i] = '/0';
	return dest;
}
char* Strcat(char* dest, char* src) {
	assert(dest != NULL);
	assert(src != NULL);
	//�ҵ�dest��ĩβ
	int64_t end = 0;
	/*while (dest[end] != '\0') {
		end++;
	}*/
	for (; dest[end] != '\0'; ++end); 
	//ƴ��
	int64_t cur = 0;
	for (; cur != '\0'; ++cur,++end) {
		dest[end] = src[cur];
	}
	dest[end] = '\0';
	//Strcpy(&dest[end], src);
	return dest;
}
int Strcmp(const char* str1, const char* str2) {
	assert(str1 != '\0');
	assert(str2 != '\0');
	while (*str1!='\0'&&*str2!='\0')
	{
		if (*str1 < *str2) {
			return -1;
		}
		else if (*str1 > *str2) {
			return 1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	if (*str1 < *str2) {
		return -1;
	}
	else if (*str1 > *str2) {
		return 1;
	}
	else
	{
		return 0;
	}
}
char* Strncpy(char* dest, char* src ,size_t num) {
	assert(dest != NULL);
	assert(src != NULL);
	for (int i = 0; i < num; ++i) {
		if (src[i] != '\0') {
			dest[i] = src[i];
		}
	}
	return dest;
}
const char* Strstr(const char* str1, const char* str2) {
  const char* p1 = str1;
  const char* p2 = str2;
  const char* pos;
  //�ж��ǲ��ǿ��ַ���
  if (*str2 == '\0') {
	  return NULL;
  }
	while (*p1!='/0')
	{
		pos = p1;
		p2 = str2;
		//��ǰ�ַ������ô
	while (*p2 != '\0'&& *pos!='\0'
		             &&(*pos == *p2)) {
					pos++;
					p2++;
			}
			if (*p2 == '/0') {
				return p1;
			}
		//����ȵ�ʱ��ָ��p1����ƶ�һλ
		//p2����ԭ��
			p1++;
	}
	      return NULL;
}
int Strtok(char* input, const char* split_char, char* output[]) {
	int output_index = 0;
	char* p = strtok(NULL, split_char);
	while (p != NULL) {
		output[output_index] = p;
		++output_index;
		p = strtok(NULL, split_char);
	}
	return output_index;
}
int main() {
	/*int arr[] = { 10,5,6,3,5 };
	BubbleSort(arr, 5,Less);
	for (int i = 0; i < 5; ++i) {
		printf("%d\n", arr[i]);
	}*/
	//int choice = Menu();
	/*if (choice == 1) {
		Add(10, 11);
	}
	else if(choice==2)
	{
		Sub(10, 5);
	}
	else if(choice==2)
	{
		Div(5, 2);
	}*/
	//������,ת���
	/*typedef int(*T)(int, int);
	T arr[] = {
		Add,
		Sub,
	    Mul,
	    Div
	};
	arr[choice - 1](10, 20);*/

	//printf("%d\n", IsLittleEnd());
	
	system("pause");
	return 0;
}