#define _CRT_SECURE_NO_WARNINGS
#define MAX 10
#define ST 5
#include <stdio.h>

int main() {
	int answer[MAX] = { 1,2,3,4,5,5,4,3,2,1 };
	int st_id[ST] = { 1,2,3,4,5 };
	int st_answer[ST][MAX] = { {1,2,3,4,5,1,1,1,1,2},
		{1,2,3,4,5,5,4,3,2,1},
		{1,2,3,4,1,2,3,4,1,2},
		{3,3,3,3,3,3,3,3,3,3},
		{1,2,1,2,1,2,1,2,1,2} };
	int st_score[ST][MAX] = { 0 };
	int st_tot_score[ST] = { 0 };
	int max = 0;
	int min = 0;

	for (int i = 0; i < ST; i++) {
		for (int j = 0; j < MAX; j++) {
			if (answer[j] == st_answer[i][j]) {
				st_score[i][j] = 1;
			}
		}
	}

	printf("학번\t답안 채점 O X 결과\t점수\n");
	for (int i = 0; i < ST; i++) {
		int score = 0;
		printf("%3d\t", st_id[i]);
		for (int j = 0; j < MAX; j++) {
			if (st_score[i][j] == 1) {
				printf("O ");
				score += 10;
			}
			else
				printf("X ");
		}
		st_tot_score[i] = score;
		printf("\t%3d\n", st_tot_score[i]);
	}
}