#include <stdio.h>
#define MAX 17

int main() {
	int arr[MAX][MAX] = { 0 };
	int(*p)[MAX] = { NULL };
	int i = 0, j = 0;
	int sw = 0;
	int cnt = 0;
	int half = MAX / 2;

	p = arr;
	cnt = 0;
	for (i = 0; i < MAX; i++) {
		sw = (i < half + 1) ? (MAX - i) : (i + 1);
		for (j = 0; j < sw; j++) {
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