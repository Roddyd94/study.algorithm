#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define box '\x25a0'

void textcolor(int color_number) { //�ܼ�â ��»����� ��Ÿ���� �Լ�
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

// Ŀ����ǥ�̵�
void gotoxy(unsigned int x, unsigned int y) {
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
COORD get_cursor() {
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

void keyDown(int(*printing)[100]) {
	int key;
	COORD position = get_cursor();
	int x = position.X;
	int y = position.Y;
	int input = _kbhit();
	if (input)
	{
		key = _getch();
		if (key == 224 || key == 0) {
			key = _getch();
			switch (key)
			{
			case 72:
				gotoxy(x, y - 1);
				break;
			case 75:
				gotoxy(x - 1, y);
				break;
			case 77:
				gotoxy(x + 1, y);
				break;
			case 80:
				gotoxy(x, y + 1);
				break;
			default:
				break;
			}
		}
		else {
			if (key == 13) {
				printing[x][y] += 1;
			}
		}
	}
}

int main() {
	COORD position;
	int tempX, tempY;
	int printing[50][100] = { 0, };

	//consol â  ũ��
	system("mode con cols=100 lines=50");
	gotoxy(0, 1);
	while (1) {
		keyDown(printing);
		position = get_cursor();
		tempX = position.X;
		tempY = position.Y;
		cursor_view(0);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 50; j++) {
				if (printing[j][i]) {
					gotoxy(j, i);
					printf("O");
				}

			}
		}
		cursor_view(1);
		gotoxy(tempX, tempY);
	}
	// �� ��â ��ü ���� �����


 // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {X��ǥ, Y��ǥ});
 // STD_OUTPUT_HANDLE ===> ���  �ܼ� â�� �ǹ���
	COORD cur = get_cursor();

	printf("cursor x = %d  y = %d", cur.X, cur.Y);
}