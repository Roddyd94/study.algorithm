#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
	char title[100];
	double rating;
}MOVIE;

void set_mv_list(MOVIE* movie_list, int movie_num);
void print_mv_list(MOVIE* movie_list, int movie_num);

int main() {
	int movie_num = 0;
	MOVIE* movie_list;
	
	printf("�� ���̳� �����Ͻðڽ��ϱ�? ");
	scanf("%d", &movie_num);

	movie_list = (MOVIE*)calloc(movie_num, sizeof(MOVIE));

	set_mv_list(movie_list, movie_num);

	print_mv_list(movie_list, movie_num);

	free(movie_list);
	movie_list = NULL;
}

void set_mv_list(MOVIE* movie_list, int movie_num) {
	for (int i = 0; i < movie_num; i++) {
		printf("��ȭ ����: ");
		scanf("%s", (movie_list + i)->title);

		printf("��ȭ ����: ");
		scanf("%lf", &(movie_list + i)->rating);
	}
}

void print_mv_list(MOVIE* movie_list, int movie_num) {
	printf("%-40s%-5s\n", "����", "����");
	for (int i = 0; i < movie_num; i++) {
		printf("%-40s%5.1lf\n", (movie_list + i)->title, (movie_list + i)->rating);
	}
}