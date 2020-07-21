#ifndef __STDIO_H__
#define __STDIO_H__ 1
#include <stdio.h>
#include <Windows.h>
#endif

void Proc_info();
void Menu_show();
void MainLoop();
int Menu_select(char select);
int Proc_end();

int main(void)
{
	Proc_info();
	MainLoop();
	return 0;
}

void Proc_info() {
	fprintf(stdout, "이 프로그램은 [은행관리프로그램]입니다. 입금 / 출금 / 잔액조회 가능\n");
}

void Menu_show(void) {
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

void MainLoop() {
	char buf = '\0';
	int con = 1;
	while (con) {
		Menu_show();
		fscanf_s(stdin, "%c", &buf, 1);
		getchar();
		con = Menu_select(buf);
	}
}

int Menu_select(char select) {
	switch (select) {
	case '1':
		fprintf(stdout, "입금하기\n");
		break;
	case '2':
		fprintf(stdout, "출금하기\n");
		break;
	case '3':
		fprintf(stdout, "잔액조회하기\n");
		break;
	case '4':
		fprintf(stdout, "종료하기\n");
		return Proc_end();
		break;
	default:
		;
	}
}

int Proc_end() {
	return 0;
}