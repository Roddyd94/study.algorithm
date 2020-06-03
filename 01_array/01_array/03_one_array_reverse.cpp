#define MAX 10
#include <stdio.h>

int main() {
	int a[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
	int temp = 0;

	for (int i = 0; i < MAX / 2; i++) {
		temp = a[i];
		a[i] = a[MAX - i - 1];
		a[MAX - i - 1] = temp;
	}
	for (int i = 0; i < MAX; i++) {
		printf("%d ", a[i]);
	}
}