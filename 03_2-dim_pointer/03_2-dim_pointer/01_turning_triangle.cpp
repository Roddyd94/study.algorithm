#define MAX 5

#include <stdio.h>

void input_triangle(int(*p)[MAX], int, int);
void turn_triangle(int(*p)[MAX], int, int);
void print_triangle(int(*p)[MAX], int, int);

int main() {
	int arr[MAX][MAX] = { 0 };
	int row = sizeof(arr) / sizeof(arr[0]);
	int col = sizeof(arr[0]) / sizeof(arr[0][0]);

	input_triangle(arr, row, col);
	print_triangle(arr, row, col);
	turn_triangle(arr, row, col);
	print_triangle(arr, row, col);


}

void input_triangle(int(*p)[MAX], int row, int col) {
	int cnt = 0;
	for (int i = 0; i < row;i++)
		for (int j = 0; j < i + 1; j++) {
			*(*(p + row - 1 - i) + col - 1 - i + j) = ++cnt;
		}
}

void turn_triangle(int(*p)[MAX], int row, int col) {
	int temp = 0;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < i + 1; j++) {
			temp = *(*(p + row - 1 - i) + col - 1 - j);
			*(*(p + row - 1 - i) + col - 1 - j) = 0;
			*(*(p + row - 1 - j) + i) = temp;
		}
}

void print_triangle(int(*p)[MAX], int row, int col) {
	printf("\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%4d", *(*(p + i) + j));
		}
		printf("\n");
	}
}