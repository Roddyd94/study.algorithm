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
					printf("���� �����̾��.\n");
					break;
				case 75:
					printf("�������η� �����̾��.\n");
					break;
				case 77:
					printf("���������� �����̾��.\n");
					break;
				case 80:
					printf("�Ʒ��� �����̾��.\n");
					break;
				default:
					break;
				}
			}
			else
			{
				if (key == 13)
					printf("enter key �����̾��\n");
				else if (key >= 65 && key <= 90)
					printf("���� �빮�� �����̾��\n");
				else if (key >= 97 && key <= 122)
					printf("���� �ҹ��� �����̾��\n");
				else if (key >= 48 && key <= 57)
					printf("���� Ű �����̾��\n");
				else
					printf("���� ����� ����??? \n");
			}
		}
	}
}