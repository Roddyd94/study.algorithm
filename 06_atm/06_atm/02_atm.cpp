#ifndef __STDIO_H__
#define __STDIO_H__ 1
#include <stdio.h>
#endif

void show_menu(void);

int main(void)
{
	show_menu();
	return 0;
}

void show_menu(void)
{
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "    ATM(�������)���α׷�\n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "1. �Ա��ϱ� \n");
	fprintf(stdout, "2. ����ϱ� \n");
	fprintf(stdout, "3. �ܾ���ȸ�ϱ� \n");
	fprintf(stdout, "4. ���� \n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "���ϴ� ��ȣ�� �Է��ϼ��� : ");
}