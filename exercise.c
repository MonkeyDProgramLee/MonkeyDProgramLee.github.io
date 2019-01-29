#include<stdio.h>
#include<string.h>
void copy_n(char dest[], char src[], int n) {
	int len_src = strlen(src);
	int len_dest = strlen(dest);
	if (len_src < n) {
		for (int i = 0; i < len_dest; ++i) {
			if (i < len_src) {
				dest[i] = src[i];
			}
			else {
				dest[i] = 'NUL';
			}
		}
	}
	if (len_src >= n) {
		for (int i = 0; i < n; ++i) {
			dest[i] = src[i];
		}
	}
}
void copyn(char dst[], char src[], int n) {
	int dst_index, src_index;
	src_index = 0;
	for (dst_index = 0; dst_index < n; dst_index += dst_index) {
		dst[dst_index] = src[src_index];
		if (src[src_index] != 0) {
			src_index += 1;
		}
	}
}
int main() {

	system("pause");
	return 0;
}