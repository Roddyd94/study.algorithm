#define MAX 5
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
	int r_cnt = 0;
	int con = 0;
	do {
		for (int i = 0; i < r_cnt && r_cnt + i < row * 2; i++) {
			if (r_cnt < row + 1)
				*(*(p + i) + r_cnt - 1 - i) = ++cnt;
			else {
				con = r_cnt - row;
				*(*(p + i + con) + r_cnt - con - 1 - i) = ++cnt;
			}
		}
		r_cnt++;
	} while (r_cnt < row * 2);
}

void print_sq(int(*p)[MAX], int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			printf("%4d", *(*(p + i) + j));
		}
		printf("\n");
	}
}