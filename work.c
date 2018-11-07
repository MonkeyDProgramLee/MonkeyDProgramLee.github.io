#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//1.实现斐波那契数即从第三项开始每一项为前两项之和
int Fibonacci(int i){
	if (i < 3){
		return 1;
	}
	return Fibonacci(i-2) + Fibonacci(i - 1);
}
//2.编写一个函数实现n^k，使用递归实现
int Exponent(int n, int i){
	if (i == 0){
		return 1;
	}
	if (n == 0){
		return 0;
	}
	return n*Exponent(n, i - 1);

}
//3.写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int num){
	return;
}
// 4.编写一个函数 reverse_string(char * string)（递归实现） 
//要求：不能使用C函数库中的字符串操作函数。
//解题思路："abcd"="abc"+"d";
//"abc" = "ab" + "c"
char reverse_string(char * string){

}
//5.递归和非递归分别实现strlen 
//6.递归和非递归分别实现求n的阶乘
int factorial(int n){
	if (n == 0){
		printf("错误的输入值");
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
//递归方式实现打印一个整数的每一位
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