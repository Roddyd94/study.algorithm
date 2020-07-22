#include <stdio.h>
#include <conio.h> 
#include <windows.h>


#define UP      72 
#define DOWN    80
#define LEFT    75
#define RIGHT   77
#define ENTER   13
#define SPACE   32


// Ŀ����ǥ�̵�
void gotoxy(unsigned int x, unsigned int y)
{
    COORD xy = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


// ���󺯰�
void set_color(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

//���� Ŀ�� ��ǥ ����
COORD get_cursor()
{
    COORD cur;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    cur.X = curInfo.dwCursorPosition.X;
    cur.Y = curInfo.dwCursorPosition.Y;
    return cur;
}

//Ŀ�������/���̱�
void cursor_view(char s)      // 0����������, 1�����麸�̱�
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = s;
    ConsoleCursor.dwSize = 2;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}