#include <stdio.h>
#include <windows.h>

int main(void)
{
	// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {X��ǥ, Y��ǥ});
	// STD_OUTPUT_HANDLE ===> ���  �ܼ� â�� �ǹ���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 20, 20 });
	printf("Hello World!");
}