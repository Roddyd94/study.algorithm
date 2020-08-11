#include "game.h"

char stage_unlocked[5] = { 1,0, };

char map_1[6][9] = {
	{ '0','0','0','0','0','0','0','0','0' },
	{ '0','1','1','1','1','1','1','K','0' },
	{ '0','1','0','D','0','0','0','0','0' },
	{ '0','1','0','1','0','1','1','1','0' },
	{ '0','S','0','1','1','1','0','G','0' },
	{ '0','0','0','0','0','0','0','0','0' }
};

char map_2[6][9] = {
	{ '0','0','0','0','0','0','0','0','0' },
	{ '0','1','1','1','1','1','1','K','0' },
	{ '0','K','0','D','0','0','0','0','0' },
	{ '0','0','0','1','0','K','0','G','0' },
	{ '0','S','1','1','1','1','D','D','0' },
	{ '0','0','0','0','0','0','0','0','0' }
};

char map_3[8][10] = {
	{ '0','0','0','0','0','0','0','0','0','0' },
	{ '0','K','1','1','1','1','D','K','K','0' },
	{ '0','1','0','D','0','0','0','D','0','0' },
	{ '0','1','0','1','0','1','D','1','0','0' },
	{ '0','1','0','1','D','1','0','1','1','0' },
	{ '0','1','0','1','0','0','0','0','D','0' },
	{ '0','S','0','1','D','1','1','D','G','0' },
	{ '0','0','0','0','0','0','0','0','0','0' }
};

char map_4[8][10] = {
	{ '0','0','0','0','0','0','0','0','0','0' },
	{ '0','K','1','1','1','1','D','K','K','0' },
	{ '0','1','0','D','0','0','0','D','0','0' },
	{ '0','1','0','1','0','G','D','1','0','0' },
	{ '0','1','0','1','D','1','0','1','1','0' },
	{ '0','1','0','1','0','0','0','0','0','0' },
	{ '0','S','0','1','D','1','1','D','G','0' },
	{ '0','0','0','0','0','0','0','0','0','0' }
};

char map_5[8][10] = {
	{ '0','0','0','0','0','0','0','0','0','0' },
	{ '0','K','1','1','1','1','D','K','K','0' },
	{ '0','1','0','D','0','0','0','D','0','0' },
	{ '0','1','0','1','0','1','D','1','0','0' },
	{ '0','1','0','1','D','1','0','1','1','0' },
	{ '0','1','0','1','0','0','0','0','D','0' },
	{ '0','S','0','1','D','1','1','D','G','0' },
	{ '0','0','0','0','0','0','0','0','0','0' }
};

STAGE stage_1 = { {9,6},*map_1 };
STAGE stage_2 = { {9,6},*map_2 };
STAGE stage_3 = { {10,8},*map_3 };
STAGE stage_4 = { {10,8},*map_4 };
STAGE stage_5 = { {10,8},*map_5 };

STAGE* stages[5] = { &stage_1,&stage_2,&stage_3,&stage_4,&stage_5 };

void draw_title()
{
	printf("\n\n\n\n");
	printf("        #####    ####     ###      ###     ####     ##### \n");
	printf("        #       #        #   #    #   #    #   #    #     \n");
	printf("        ####     ###     #        #####    ####     ####  \n");
	printf("        #           #    #   #    #   #    #        #     \n");
	printf("        #####   ####      ###     #   #    #        ##### \n");
}

void draw_menu()
{
	set_pos(0, 0);
	draw_title();
	set_pos(27, 12);
	printf("게임 시작");
	set_pos(27, 13);
	printf("게임 정보");
	set_pos(27, 14);
	printf("종     료");
	set_pos(25, 12);
	printf(">");
}

char select_menu()
{
	char key = 0;
	COORD pos = { NULL };

	draw_menu();

	while (key != ENTER)
	{
		pos = get_pos();
		key = get_key();
		set_pos(25, pos.Y);
		printf(" ");

		switch (key)
		{
		case UP:
			(pos.Y == 12) ? set_pos(25, pos.Y) : set_pos(25, pos.Y - 1);
			printf(">");
			break;
		case DOWN:
			(pos.Y == 14) ? set_pos(25, pos.Y) : set_pos(25, pos.Y + 1);
			printf(">");
			break;
		case ENTER:
			return pos.Y - 11;
		default:
			set_pos(pos.X - 1, pos.Y);
			printf(">");
			break;

		}
	}
}

char select_stage()
{
	char key = 0;
	char pos = 0;

	char stage = 1;

	system("cls");

	set_pos(0, 0);
	draw_title();

	set_pos(27, 12);
	printf("< Stage 1 >");

	set_pos(29, 14);
	printf("Back");

	while (1)
	{
		key = get_key();

		set_pos(25, 10);
		printf("            ");

		switch (key)
		{
		case UP:
			set_pos(27, 14);
			printf(" ");
			set_pos(27, 12);
			printf("<");
			set_pos(37, 12);
			printf(">");
			pos = 0;
			break;
		case DOWN:
			set_pos(27, 12);
			printf(" ");
			set_pos(37, 12);
			printf(" ");
			set_pos(27, 14);
			printf(">");
			pos = 1;
			break;
		case LEFT:
			if (!pos)
			{
				(stage == 1) ? (stage) : (stage--);
			}
			break;
		case RIGHT:
			if (!pos)
			{
				(stage == 5) ? (stage) : (stage++);
			}
			break;
		case ENTER:
			if (pos)
			{
				return 0;
			}
			else if (stage_unlocked[stage - 1])
			{
				return stage;
			}
			else
			{
				set_pos(25, 10);
				printf("Stage Locked");
			}
			break;
		case ESC:
			return 0;
		default:
			break;
		}

		set_pos(29, 12);
		printf("Stage %d", stage);
	}
}

char start_stage(char stage)
{
	char tile = 0;
	char check = 0;
	char key = 0;
	char keys = 0;


	if (!stage) return 1;

	system("cls");
	set_pos(29, 8);
	printf("Stage %d", stage);
	Sleep(2000);

	stage--;
	char* stage_map = (char*)malloc(sizeof(char)
		* stages[stage]->stage_size.X
		* stages[stage]->stage_size.Y);

	memset(stage_map, '0', sizeof(char)
		* stages[stage]->stage_size.X
		* stages[stage]->stage_size.Y);

	for (int i = 0; i < stages[stage]->stage_size.X
		* stages[stage]->stage_size.Y; i++)
	{
		stage_map[i] = *(stages[stage]->map + i);
	}
	COORD stage_pos = { SCREEN_WIDTH / 2 - stages[stage]->stage_size.X / 2,
		SCREEN_HEIGHT / 2 - stages[stage]->stage_size.Y / 2 };
	COORD pos = { NULL };

	system("cls");

	set_pos(8, 4);
	printf("Key %d", keys);
	for (int i = 0; i < stages[stage]->stage_size.Y; i++)
	{
		set_pos(stage_pos.X, stage_pos.Y + i);
		for (int j = 0; j < stages[stage]->stage_size.X; j++)
		{
			tile = stage_map[stages[stage]->stage_size.X * i + j];
			switch (tile)
			{
			case '0':
				set_icon(WALL);
				break;
			case '1':
				set_icon(FLOOR);
				break;
			case 'D':
				set_icon(DOOR);
				break;
			case 'K':
				set_icon(KEY);
				break;
			case 'S':
				set_icon(PLAYER);
				pos.X = get_pos().X - 1;
				pos.Y = get_pos().Y;
				break;
			case 'G':
				set_icon(GOAL);
				break;
			default:
				break;
			}
		}
	}

	set_pos(pos.X, pos.Y);
	while (check != 2)
	{
		key = get_key();
		pos = get_pos();
		
		switch (key)
		{
		case UP:
			tile = stage_map[stages[stage]->stage_size.X 
				* (pos.Y - stage_pos.Y - 1) 
				+ (pos.X - stage_pos.X)];
			check = check_tile(tile, &keys);
			if (check) {
				stage_map[stages[stage]->stage_size.X
					* (pos.Y - stage_pos.Y - 1)
					+ (pos.X - stage_pos.X)] = '1';
				set_pos(pos.X, pos.Y);
				set_icon(FLOOR);
				set_pos(pos.X, pos.Y - 1);
				set_icon(PLAYER);
				set_pos(pos.X, pos.Y - 1);
			}
			break;
		case DOWN:
			tile = stage_map[stages[stage]->stage_size.X 
				* (pos.Y - stage_pos.Y + 1) 
				+ (pos.X - stage_pos.X)];
			check = check_tile(tile, &keys);
			if (check) {
				stage_map[stages[stage]->stage_size.X
					* (pos.Y - stage_pos.Y + 1)
					+ (pos.X - stage_pos.X)] = '1';
				set_pos(pos.X, pos.Y);
				set_icon(FLOOR);
				set_pos(pos.X, pos.Y + 1);
				set_icon(PLAYER);
				set_pos(pos.X, pos.Y + 1);
			}
			break;
		case LEFT:
			tile = stage_map[stages[stage]->stage_size.X
				* (pos.Y - stage_pos.Y)
				+ (pos.X - stage_pos.X - 1)];
			check = check_tile(tile, &keys);
			if (check) {
				stage_map[stages[stage]->stage_size.X
					* (pos.Y - stage_pos.Y)
					+ (pos.X - stage_pos.X - 1)] = '1';
				set_pos(pos.X, pos.Y);
				set_icon(FLOOR);
				set_pos(pos.X - 1, pos.Y);
				set_icon(PLAYER);
				set_pos(pos.X - 1, pos.Y);
			}
			break;
		case RIGHT:
			tile = stage_map[stages[stage]->stage_size.X
				* (pos.Y - stage_pos.Y)
				+ (pos.X - stage_pos.X + 1)];
			check = check_tile(tile, &keys);
			if (check) {
				stage_map[stages[stage]->stage_size.X
					* (pos.Y - stage_pos.Y)
					+ (pos.X - stage_pos.X + 1)] = '1';
				set_pos(pos.X, pos.Y);
				set_icon(FLOOR);
				set_pos(pos.X + 1, pos.Y);
				set_icon(PLAYER);
				set_pos(pos.X + 1, pos.Y);
			}
			break;
		case ESC:
			return 1;
		default:
			break;
		}
	}
	free(stage_map);
	stage_map = NULL;
	if (stage < 4)
	{
		stage_unlocked[stage + 1] = 1;
		return start_stage(stage + 2);
	}
	else if (stage == 4)
	{
		system("cls");
		set_pos(25, 8);
		printf("Congratulation", stage);
		Sleep(2000);
	}
	else return 1;
}

void set_icon(char entity)
{
	switch (entity)
	{
	case WALL:
		set_color(BLACK, WHITE);
		printf(" ");
		set_color(WHITE, BLACK);
		break;
	case PLAYER:
		set_color(WHITE, BLACK);
		printf("O");
		break;
	case GOAL:
		set_color(GREEN, BLACK);
		printf("O");
		set_color(WHITE, BLACK);
		break;
	case DOOR:
		set_color(DARK_YELLOW, BLACK);
		printf("X");
		set_color(WHITE, BLACK);
		break;
	case KEY:
		set_color(YELLOW, BLACK);
		printf("*");
		set_color(WHITE, BLACK);
		break;
	case FLOOR:
		set_color(WHITE, BLACK);
		printf(" ");
		break;
	default:
		break;
	}
}

void show_info()
{
	system("cls");

	set_pos(8, 4);
	set_icon(PLAYER);
	printf(" is you");

	set_pos(8, 5);
	set_icon(GOAL);
	printf(" is the goal");

	set_pos(8, 6);
	set_icon(WALL);
	printf(" is a wall");

	set_pos(8, 7);
	set_icon(DOOR);
	printf(" is a door");

	set_pos(8, 8);
	set_icon(KEY);
	printf(" is a key");

	set_pos(8, 10);
	set_color(WHITE, BLACK);
	printf("Press ESC to return to menu");

	while (1)
	{
		char key = get_key();
		if (key == ENTER || key == ESC) break;
	}
}

char check_tile(char tile, char* keys)
{
	char* key = keys;
	switch (tile)
	{
	case '0':
		return 0;
		break;
	case 'D':
		if (*key > 0)
		{
			*key -= 1;
			set_pos(8, 4);
			printf("Key %d", *key);
			return 1;
		}
		else return 0;
		break;
	case 'K':
		*key += 1;
		set_pos(8, 4);
		printf("Key %d", *key);
		return 1;
		break;
	case 'G':
		return 2;
		break;
	default:
		return 1;
		break;
	}
}