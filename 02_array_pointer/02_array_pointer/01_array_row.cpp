#include <stdio.h>
#define MAX 5

int main() {
	int arr[MAX][MAX] = { 0 };
	int(*p)[MAX] = { NULL };
	int i = 0, j = 0;

	p = arr;

	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			*(*(p + i) + j) = MAX * i + j + 1;
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