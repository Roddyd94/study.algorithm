#include "main.h"

int main()
{
	char menu = 0;
	set_screen(SCREEN_WIDTH, SCREEN_HEIGHT, (WCHAR*)L"≈ª√‚ ∞‘¿”");
	set_cursor(0);

	do
	{
		system("cls");
		draw_title();
		menu = select_menu();

		switch (menu)
		{
		case 1:
			while (!start_stage(select_stage()));
			break;
		case 2:
			show_info();
			break;
		case 3:
			system("cls");
			exit(0);
			break;
		default:
			break;
		}
	} while (menu);
	_getch();
}