#include <stdio.h>
#define MAX 17

int main() {
	int arr[MAX][MAX] = { 0 };
	int(*p)[MAX] = { NULL };
	int i = 0, j = 0;
	int sw = 0;

	p = arr;
	sw = 0;
	for (i = 0; i < MAX; i++) {
		sw = i % 2;
		for (j = 0; j < MAX; j++) {
			*(*(p + i) + j) = (i + sw) * MAX + (j + 1) * (1 - sw) - j * sw;
		}
	}

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (arr[i][j])
				printf("%3d", arr[i][j]);
			else
				printf("   ");
		}
		printf("\n");
	}
}