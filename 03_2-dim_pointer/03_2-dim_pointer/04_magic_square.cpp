#define MAX 5	// È¦¼ö¸¸ °¡´É
#include <stdio.h>

void input_sq(int(*p)[MAX], int);
void print_sq(int(*p)[MAX], int);

int main() {
	int arr[MAX][MAX] = { 0 };
	int row = sizeof(arr) / sizeof(arr[0]);

	input_sq(arr, row);
	print_sq(arr, row);
}

void input_sq(int(*p)[MAX], int row) {
	int cnt = 0;
	int step = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			*(*(p + (row  - j +2* i) % row) + (row + row / 2 + j - i) % row) = ++cnt;
		}
	}
}

void print_sq(int(*p)[MAX], int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			printf("%4d", *(*(p + i) + j));
		}
		printf("\n");
	}
}