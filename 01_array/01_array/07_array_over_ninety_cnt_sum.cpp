#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#include <stdio.h>

int main() {
	int a[MAX] = { 0 };
	int cnt = 0;
	int sum = 0;

	for (int i = 0; i < MAX; i++) {
		printf("a[%d] : ", i);
		scanf("%d", a + i);
		if (a[i] >= 90) {
			cnt++;
			sum += a[i];
		}
	}
	printf("\n");
	for (int i = 0; i < MAX; i++) {
		printf("%3d ", a[i]);
	}
	printf("\nsum : %d, count : %d", sum, cnt);
}