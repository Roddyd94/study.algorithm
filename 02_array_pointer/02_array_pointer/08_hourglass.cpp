#include <stdio.h>
#define MAX 17

int main() {
	int arr[MAX][MAX] = { 0 };
	int(*p)[MAX] = { NULL };
	int i = 0, j = 0;
	int sw_i = 0;
	int sw_j = 0;
	int cnt = 0;
	int half = MAX / 2;

	p = arr;
	cnt = 0;
	for (i = 0; i < MAX; i++) {
		sw_i = (i < half + 1) ? (half - i) : (i - half);
		for (j = 0; j < 2 * sw_i + 1; j++) {
			sw_j = (i < half + 1) ? (i) : (MAX - 1 - i);
			*(*(p + i) + sw_j + j) = ++cnt;
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