#include <stdio.h>
#include <conio.h> 
#include <windows.h>


#define UP      72 
#define DOWN    80
#define LEFT    75
#define RIGHT   77
#define ENTER   13
#define SPACE   32


// 커서좌표이동
void gotoxy(unsigned int x, unsigned int y)
{
    COORD xy = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}


// 색상변경
void set_color(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

//현재 커서 좌표 추출
COORD get_cursor()
{
    COORD cur;
    CONSOLE_SCREEN_BUFFER_INFO curInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
    cur.X = curInfo.dwCursorPosition.X;
    cur.Y = curInfo.dwCursorPosition.Y;
    return cur;
}

//커서숨기기/보이기
void cursor_view(char s)      // 0넣으면숨기기, 1넣으면보이기
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = s;
    ConsoleCursor.dwSize = 2;
    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}