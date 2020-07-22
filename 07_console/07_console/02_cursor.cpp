#include <stdio.h>
#include <windows.h>

int main(void)
{
	// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {X좌표, Y좌표});
	// STD_OUTPUT_HANDLE ===> 출력  콘솔 창을 의미함
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 20, 20 });
	printf("Hello World!");
}