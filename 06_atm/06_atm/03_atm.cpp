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
	fprintf(stdout, "�� ���α׷��� [����������α׷�]�Դϴ�. �Ա� / ��� / �ܾ���ȸ ����\n");
}

void Menu_show(void) {
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
		fprintf(stdout, "�Ա��ϱ�\n");
		break;
	case '2':
		fprintf(stdout, "����ϱ�\n");
		break;
	case '3':
		fprintf(stdout, "�ܾ���ȸ�ϱ�\n");
		break;
	case '4':
		fprintf(stdout, "�����ϱ�\n");
		return Proc_end();
		break;
	default:
		;
	}
}

int Proc_end() {
	return 0;
}