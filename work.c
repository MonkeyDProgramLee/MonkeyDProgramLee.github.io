#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1.ʵ��쳲����������ӵ����ʼÿһ��Ϊǰ����֮��
int Fibonacci(int i){
	if (i < 3){
		return 1;
	}
	return Fibonacci(i-2) + Fibonacci(i - 1);
}
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
int Exponent(int n, int i){
	if (i == 0){
		return 1;
	}
	if (n == 0){
		return 0;
	}
	return n*Exponent(n, i - 1);

}
//3.дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ� 
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
int DigitSum(int num){
	return;
}
// 4.��дһ������ reverse_string(char * string)���ݹ�ʵ�֣� 
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
//����˼·��"abcd"="abc"+"d";
//"abc" = "ab" + "c"
char reverse_string(char * string){

}
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
int factorial(int n){
	if (n == 0){
		printf("���������ֵ");
	}
	if (n == 1){
		return 1;
	}
	return n*factorial(n - 1);
}
int Factorial(int n){
	int i,ret=1;
	 while(i <= n){
		 ret = ret*n;
	}
}
//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
int digit(int num){
	if (num < 10){
		return num % 10;
	}
	return;

}
int main(){
	printf("%d\n", Fibonacci(3));
	printf("%d\n", Exponent(2, 1));
	printf("%d\n", factorial(5));
}