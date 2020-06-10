#include <stdio.h>
#define MAX 17

int main() {
	int arr[MAX][MAX] = { 0 };
	int(*p)[MAX] = { NULL };
	int i = 0, j = 0;
	int cnt = 0;

	p = arr;
	cnt = 0;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < i + 1; j++) {
			*(*(p + i) + j) = ++cnt;
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