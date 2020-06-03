#define MAX 10
#include <stdio.h>

int main() {
	int a[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
	int b[MAX] = { 0 };

	for (int i = 0; i < MAX; i++) {
		b[(i + 5) % 10] = a[i];
	}
	for (int i = 0; i < MAX; i++) {
		printf("%d ", b[i]);
	}
}