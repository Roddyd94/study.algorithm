#define MAX 9
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
	int i = 0;
	int j = -1;
	int dir = 1;
	int len = row;
	int step = 0;
	int cnt = 0;

	while (len > 0) {
		for (step = 0; step < len; step++) {
			if (step < len)
				j += dir;
			*(*(p + i) + j) = ++cnt;
		}
		len--;
		for (step = 0; step < len; step++) {
			if (step < len)
				i += dir;
			*(*(p + i) + j) = ++cnt;
		}
		dir = -dir;
	}
}

/*
void input_sq(int(*p)[MAX], int row) {
	int i[2] = { 0 };
	int cnt = 0;
	int r_cnt = 0;
	int sw = 0;
	int sign = 0;
	int con = 0;
	int len = row - 1;
	while (r_cnt / 2 < row) {
		sw = !((r_cnt % 4) / 2);
		sign = 2 * sw - 1;
		con = (sw * len) + (2 * !sw - 1) * (r_cnt / 4);
		for (; sign * i[r_cnt % 2] < sign * con; i[r_cnt % 2] += sign) {
			*(*(p + i[1]) + i[0]) = ++cnt;
		}
		r_cnt++;
		i[0] += !(r_cnt % 4);
		i[1] += !(r_cnt % 4);
	}
	if (row % 2)
		*(*(p + row / 2) + row / 2) = ++cnt;
}
*/

void print_sq(int(*p)[MAX], int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < row; j++) {
			printf("%4d", *(*(p + i) + j));
		}
		printf("\n");
	}
}