#include<stdio.h>
#include<stdlib.h>
int IsLittleEnd() {
	int a = 0x11223344;
	char* b = (char*)&a;
	if (*b == 0x11) {
		//取出高位
		return 0;
	}
		return -1;
}
int main() {
	printf("%d\n", IsLittleEnd());
	system("pause");
	return 0;
}