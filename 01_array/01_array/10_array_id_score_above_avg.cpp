#define _CRT_SECURE_NO_WARNINGS
#define MAX 30
#include <stdio.h>

int main() {
	int id[MAX] = { 0 };
	int score[MAX] = { 0 };
	int sum = 0;
	int avg = 0;
	int cnt = 0;
	int check = 0;

	for (int i = 0; i < MAX; i++) {
		while (1) {
			printf("�й�[%d], ����[%d] : ", i, i);
			scanf("%d%d", id + i, score + i);
			for (int j = 0; j < cnt; j++) {
				if (id[j] == id[i]) {
					printf("�й��� ������ �� �����ϴ�.\n");
					printf("�й��� �ٽ� �Է����ּ���.\n");
					check = 1;
				}
			}
			if (!check) {
				break;
			}
			check = 0;
		}
		if (id[i] == 999||score[i] == 999)
			break;
		cnt++;
		sum += score[i];
	}
	avg = sum / cnt;
	printf("\n");
	for (int i = 0; i < cnt; i++) {
		if (score[i] > avg)
			printf("%2d ", id[i]);
	}
}