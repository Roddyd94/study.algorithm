#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  S_SIZE  5

typedef struct NODE {
	char title[S_SIZE];
	int year;
	struct NODE* link;
}NODE;

int main() {
	{
		NODE* list = NULL;
		NODE* prev = NULL, * p, * next;
		char buf[S_SIZE];
		int year;

		while (1) {
			printf("책의 제목 입력 : (종료하려면 엔터) : ");
			gets_s(buf);
			if (buf[0] == '\0')
				break;
			p = (NODE*)malloc(sizeof(NODE));
			strcpy(p->title, buf);
			printf("책의 출판연도 : ");
			gets_s(buf);
			year = atoi(buf);
			p->year = year;

			if (list == NULL)
				list = p;
			else if (prev != NULL)
				prev->link = p;
			p->link = NULL;
			prev = p;
		}

		// 연결 리스트에 들어 있는 정보를 모두 출력
		p = list;
		while (p != NULL) {
			printf("책 제목 : %20s, 출판연도 : %10d \n", p->title, p->year);
			p = p->link;
		}

		// 동적 할당 반납
		p = list;
		while (p != NULL) {
			next = p->link;
			free(p);
			p = next;
		}
	}
}