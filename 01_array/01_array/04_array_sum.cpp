#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>

int main() {
	int a[MAX] = { 0 };
	int b[MAX] = { 0 };
	int c[MAX] = { 0 };

	for (int i = 0; i < MAX; i++) {
		printf("a[%d] b[%d] : ", i, i);
		scanf("%d%d", a + i, b + i);
	}
	for (int i = 0; i < MAX; i++) {
		c[i] = a[i] + b[i];
	}
	for (int i = 0; i < MAX; i++) {
		printf("%d ", c[i]);
	}
}