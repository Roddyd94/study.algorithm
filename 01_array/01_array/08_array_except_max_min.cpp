#define _CRT_SECURE_NO_WARNINGS
#define MAX 7
#include <stdio.h>

int main() {
	int a[MAX] = { 0 };
	int max = 0;
	int min = 0;

	for (int i = 0; i < MAX; i++) {
		printf("a[%d] : ", i);
		scanf("%d", a + i);
		if (!i) {
			max = a[i];
			min = a[i];
		}
		else {
			if (a[i] > max)
				max = a[i];
			if (a[i] < min)
				min = a[i];
		}
	}
	printf("\n");
	for (int i = 0; i < MAX; i++) {
		if (a[i] != max && a[i] != min)
			printf("%d ", a[i]);
	}
}