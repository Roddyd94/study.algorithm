#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie {
	char title[100];
	double rating;
	struct movie* link;
}MOVIE;

void set_mv_list(MOVIE** movie_list, int movie_num);
void free_mv_list(MOVIE* movie_list);
void print_mv_list(MOVIE* movie_list);

int main() {
	int movie_num = 0;
	MOVIE* movie_list = NULL;

	printf("몇 편이나 저장하시겠습니까? ");
	scanf("%d", &movie_num);

	set_mv_list(&movie_list, movie_num);

	print_mv_list(movie_list);

	free_mv_list(movie_list);
	movie_list = NULL;
}

void set_mv_list(MOVIE** movie_list, int movie_num) {
	MOVIE* prev = NULL, * p;

	for (int i = 0; i < movie_num; i++) {
		p = (MOVIE*)malloc(sizeof(MOVIE));
		memset(p, 0, sizeof(MOVIE));

		if (prev != NULL)
			prev->link = p;

		printf("영화 제목: ");
		scanf("%s", p->title);

		printf("영화 평점: ");
		scanf("%lf", &(p->rating));

		if (*movie_list == NULL)
			*movie_list = p;

		prev = p;
	}
}

void free_mv_list(MOVIE* movie_list) {
	MOVIE* prev = NULL, * p;

	p = movie_list;
	while (p != NULL) {
		prev = p;
		p = prev->link;
		free(prev);
	}
	free(p);
	p = NULL;
	prev = NULL;
}

void print_mv_list(MOVIE* movie_list) {
	MOVIE* p;

	printf("%-40s%-5s\n", "제목", "평점");
	p = movie_list;

	while (p != NULL) {
		printf("%-40s%5.1lf\n", p->title, p->rating);
		p = p->link;
	}
}