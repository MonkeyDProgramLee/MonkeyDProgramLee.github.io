#include<stdio.h>
#include<stdlib.h>
int IsLittleEnd() {
	int a = 0x11223344;
	char* b = (char*)&a;
	if (*b == 0x11) {
		//ȡ����λ
		return 0;
	}
		return -1;
}
int Add(int x, int y) {
	return x + y;
}
int Sub(int x, int y) {
	return x - y;
}
int Mul(int x, int y) {
	return x * y;
}
int Div(int x, int y) {
	return x / y;
}
//int Menu() {
//	int choice;
//	return choice;
//}
void Swp(int* x, int* y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
//����������һ������ָ�������������
typedef int(*T)(int x,int y);
void BubbleSort(int arr[],int size,T cmp) {
	int bound;
	for (bound = size; bound > 0; --bound) {
		for (int i = 0; i < bound; ++i) {
			if (cmp(arr[i], arr[i + 1])==0) {
				Swp(&arr[i], &arr[i + 1]);
			}
		}
	}
}
//LessΪ�ص�����
int Less(int x, int y) {
	return x < y ? 1 : 0;
}
int Greater(int x, int y) {
	return x > y ? 1 : 0;
}
//int AbsLess(int x, int y) {
//	return
//}
int main() {
	int arr[] = { 10,5,6,3,5 };
	BubbleSort(arr, 5,Less);
	for (int i = 0; i < 5; ++i) {
		printf("%d\n", arr[i]);
	}
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