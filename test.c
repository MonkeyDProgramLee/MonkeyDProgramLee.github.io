#include<stdio.h>
#include<stdlib.h>
void swp(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void swp2(char* a, char* b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void paosort(int arr[], int size){
	int boundary;
	for (boundary = size; boundary > 0; --boundary){
		for (int i = 0; i < boundary; ++i){
			if (arr[boundary]>arr[i]){
				swp(&arr[boundary], &arr[i]);
			}
		}
	}
}
int main(){
 //   int	arr[] = { 1, 5, 2, 4, 7 };
	//int boundary;
	//int len = sizeof(arr) / sizeof(arr[0]);
	//boundary = len - 1;//数组的长度为边界
	//for (; boundary > 0; --boundary){
	//	for (int i = 0; i < boundary; ++i){
	//		if (arr[boundary] < arr[i]){
	//			swp(&arr[boundary],&arr[i]);
	//		}
	//	}
	//}
	//paosort(&arr[0], len);
	//for (int i = 0; i < len; ++i){
	//	printf("%d\n",arr[i]);
	//}
	char str1[] = "hello world";
	char str2[] = "###########";
	int left = 0;
	int lenth = sizeof(str1) / sizeof(str2[0]);
	int right = lenth - 1;
	while (left<right)
	{
		swp2(&str1[left], &str2[left]);
		swp2(&str1[right], &str2[right]);
		for (int i = 0; i < lenth; ++i){
			printf("%s\n", str1[i]);
		}
		left++;
		right--;
	}
	
}