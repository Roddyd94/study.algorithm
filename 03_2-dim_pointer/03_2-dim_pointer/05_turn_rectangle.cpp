#define ROW 5
#define COL 3

#include <stdio.h>

void input_rectangle(int(*p)[COL], int, int);
void turn_rectangle(int(*pa)[COL], int(*pb)[ROW], int, int);
void print_rectangle_a(int(*p)[COL], int, int);
void print_rectangle_b(int(*p)[ROW], int, int);

int main() {
	int arr_a[ROW][COL] = { 0 };
	int arr_b[COL][ROW] = { 0 };
	int row = sizeof(arr_a) / sizeof(arr_a[0]);
	int col = sizeof(arr_a[0]) / sizeof(arr_a[0][0]);

	input_rectangle(arr_a, row, col);
	print_rectangle_a(arr_a, row, col);

	row = sizeof(arr_b) / sizeof(arr_b[0]);
	col = sizeof(arr_b[0]) / sizeof(arr_b[0][0]);
	turn_rectangle(arr_a, arr_b, row, col);
	print_rectangle_b(arr_b, row, col);


}

void input_rectangle(int(*p)[COL], int row, int col) {
	int cnt = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			*(*(p + i) + j) = ++cnt;
		}
}

void turn_rectangle(int(*pa)[COL], int(*pb)[ROW], int row, int col) {
	int temp = 0;
	int cnt = 0;
	for (cnt = 0; cnt < row*col; cnt++) {
		temp = *(*pa + cnt);
		*(*pa + cnt) = *(*pb + cnt);
		*(*pb + cnt) = temp;
	}
}

void print_rectangle_a(int(*p)[COL], int row, int col) {
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%4d", *(*(p + i) + j));
		}
		printf("\n");
	}
}

void print_rectangle_b(int(*p)[ROW], int row, int col) {
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%4d", *(*(p + i) + j));
		}
		printf("\n");
	}
}