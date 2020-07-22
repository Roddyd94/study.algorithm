#include <stdio.h>
#include <conio.h>

int main() {
	int key;
	int i = 0;

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
				case 72:
					printf("위로 누르셨어요.\n");
					break;
				case 75:
					printf("왼쪽으로로 누르셨어요.\n");
					break;
				case 77:
					printf("오른쪽으로 누르셨어요.\n");
					break;
				case 80:
					printf("아래로 누르셨어요.\n");
					break;
				default:
					break;
				}
			}
			else
			{
				if (key == 13)
					printf("enter key 누르셨어요\n");
				else if (key >= 65 && key <= 90)
					printf("영어 대문자 누르셨어요\n");
				else if (key >= 97 && key <= 122)
					printf("영어 소문자 누르셨어요\n");
				else if (key >= 48 && key <= 57)
					printf("숫자 키 누르셨어요\n");
				else
					printf("나도 몰라요 뭔지??? \n");
			}
		}
	}
}