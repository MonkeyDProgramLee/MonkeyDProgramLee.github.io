//用二分法查找数组里的数字
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
//int main(){
//	int arr[] = { 1, 2, 3, 4, 5 };
//	int to_find;
//	printf("请输入要查找的数字：\n");
//	scanf("%d", &to_find);
//	int left = 0;
//	int len = sizeof(arr) / sizeof(arr[0]);
//    int right= len - 1;
//	int mid;
//	while (left <= right){
//		mid = left + (right - left) / 2;
//		if (to_find < arr[mid]){
//			right = mid - 1;
//		}
//		else if (to_find>arr[mid])
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (left <= right){
//		printf("找到了 i=%d", mid);
//	}
//	else
//	{
//		printf("没找到");
//	}
//}
//二分法查找方程在（-10,10)之间的根
//int main(){
//	double hs(double a);
//	double left = -10;
//	double right = 10;
//	double mid;
//	while (left<=right)
//	{
//		mid = (left + right) / 2;
//		if (hs(mid)>0){
//			right=mid;
//		}
//		else if (hs(mid) < 0){
//			left = mid;
//		}
//		else{
//			printf("%d", (int)mid);
//			printf("%lf",mid);
//			break;
//		}
//	}
//}
//double hs(double a){
//	double sum;
//	sum=2 * pow(a, 3) - 4 * pow(a, 2) + 3 * a - 6;
//	return sum;
//}
//画一个菱形
int main(){
	srand(time(0));
	int to_find = rand()%1000-1;
	printf("%d", to_find);
}