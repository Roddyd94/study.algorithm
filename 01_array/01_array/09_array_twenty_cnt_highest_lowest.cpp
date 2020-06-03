#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#include <stdio.h>

int main() {
	int s[MAX] = { 0 };
	int max = 0;
	int min = 0;
	int max_cnt = 0;
	int min_cnt = 0;

	for (int i = 0; i < MAX; i++) {
		printf("a[%d] : ", i);
		scanf("%d", s + i);
		if (!i) {
			max = s[i];
			max_cnt = 1;
			min = s[i];
			min_cnt = 1;
		}
		else {
			if (s[i] > max) {
				max = s[i];
				max_cnt = 1;
			}
			else if (s[i] == max)
				max_cnt++;
			if (s[i] < min) {
				min = s[i];
				min_cnt = 1;
			}
			else if (s[i] == min)
				min_cnt++;
		}
	}
	for (int i = 0; i < MAX; i++) {
		if (i % 10 == 0)
			printf("\n");
		printf("%4d ", s[i]);
	}
	printf("\nthe number of max scores : %d\nthe number of min scores : %d", max_cnt, min_cnt);
}