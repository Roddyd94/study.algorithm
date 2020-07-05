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
			printf("å�� ���� �Է� : (�����Ϸ��� ����) : ");
			gets_s(buf);
			if (buf[0] == '\0')
				break;
			p = (NODE*)malloc(sizeof(NODE));
			strcpy(p->title, buf);
			printf("å�� ���ǿ��� : ");
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

		// ���� ����Ʈ�� ��� �ִ� ������ ��� ���
		p = list;
		while (p != NULL) {
			printf("å ���� : %20s, ���ǿ��� : %10d \n", p->title, p->year);
			p = p->link;
		}

		// ���� �Ҵ� �ݳ�
		p = list;
		while (p != NULL) {
			next = p->link;
			free(p);
			p = next;
		}
	}
}