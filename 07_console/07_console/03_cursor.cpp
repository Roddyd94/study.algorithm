#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
void cur(short x, short y)		//화면의 원하는 x, y좌표로 보냄
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
	system("mode con cols=30 lines=40");
	getchar();
	srand((unsigned int)time(NULL));
	while (1)
	{
		cur((rand() % 60) / 2, rand() % 40);
		printf("*");
		Sleep(100);
	}
}