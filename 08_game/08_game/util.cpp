#include "util.h"

void set_pos(short x, short y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void set_color(char color, char bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void set_screen(short width, short height, WCHAR* title)
{
	char* msg = NULL;

	msg = (char*)malloc(30);
	memset(msg, '\0', 30);

	sprintf_s(msg, 30, "%s%d%s%d", "mode con cols=", width, " lines=", height);
	system(msg);
	system("cls");
	SetConsoleTitle((LPCWSTR)title);

	free(msg);
}

COORD get_pos()
{
	COORD cur;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	cur.X = curInfo.dwCursorPosition.X;
	cur.Y = curInfo.dwCursorPosition.Y;
	return cur;
}

void set_cursor(char state)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = state;
	ConsoleCursor.dwSize = 2;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void init_rand()
{
	srand((unsigned int)time(NULL));
}

char get_key()
{
	int key = 0;
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 224 || key == 0)
			{
				key = _getch();
				switch (key)
				{
				case K_UP:
					return UP;
					break;
				case K_DOWN:
					return DOWN;
					break;
				case K_LEFT:
					return LEFT;
					break;
				case K_RIGHT:
					return RIGHT;
					break;
				default:
					break;
				}
			}
			else
			{
				switch (key)
				{
				case K_ENTER:
					return ENTER;
					break;
				case K_SPACE:
					return SPACE;
					break;
				case K_ESC:
					return ESC;
					break;
				default:
					break;
				}
			}
		}
	}
}