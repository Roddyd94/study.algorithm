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
	fprintf(stdout, "    ATM(은행관리)프로그램\n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "1. 입금하기 \n");
	fprintf(stdout, "2. 출금하기 \n");
	fprintf(stdout, "3. 잔액조회하기 \n");
	fprintf(stdout, "4. 종료 \n");
	fprintf(stdout, "-------------------------------\n");
	fprintf(stdout, "원하는 번호를 입력하세요 : ");
}