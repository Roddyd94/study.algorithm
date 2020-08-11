#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

static char direction[4][2] = {
	{0,-1},
	{-1,0},
	{1,0},
	{0,1} };
static char cursor_state = 1;
static char window_col_size = 0;
static char window_line_size = 0;
static char sel_color[15] = { 0, };
static char team_color[14] = { 0, };
static char team_num = 0;
static char team_p_or_c[14] = { 1, 0, };

struct unit {
	short x;
	short y;
	char team;		// color
	char unit_num;	// unique
	char unit_type;	// shape
	struct unit* link;
};


void set_window_size(int col, int line);
void set_color(char color);
void set_cursor(short x, short y);
void set_team(struct unit** players);
void set_unit(struct unit* players);
char move_cursor();
void move_unit(struct unit* _unit, char dir);
void view_cursor(char state);

int main(void) {
	srand((unsigned int)time(NULL));
	struct unit* teams = NULL;

	view_cursor(0);
	set_window_size(window_col_size = 100, window_line_size = 40);
	set_team(&teams);
	set_unit(teams);
	while (1) {
		for (int i = 0; i < team_num; i++) {
			if (team_p_or_c[i])
				move_unit((teams + i), move_cursor());
			else
				move_unit((teams + i), rand() % 4);
		}
	}
}

void set_window_size(int col, int line) {
	char* con_result = NULL;
	char* con_strs[2] = { (char*)"mode con cols=",(char*)" lines=" };
	char* c_temp = NULL;

	int line_length = 0;

	c_temp = (char*)malloc(12 * sizeof(char));

	_itoa_s(col, c_temp, 11, 10);
	line_length = strlen(con_strs[0]) + strlen(con_strs[1])
		+ strlen(c_temp);

	_itoa_s(line, c_temp, 11, 10);
	line_length += strlen(c_temp) + 2;

	con_result = (char*)malloc(line_length);

	strcpy_s(con_result, line_length, con_strs[0]);
	_itoa_s(col, c_temp, 11, 10);
	strcat_s(con_result, line_length, c_temp);
	strcat_s(con_result, line_length, con_strs[1]);
	_itoa_s(line, c_temp, 11, 10);
	strcat_s(con_result, line_length, c_temp);

	SetConsoleTitle((LPCWSTR)L"sdf");
	system(con_result);
	system("cls");

	free(con_result);
	con_result = NULL;
	free(c_temp);
	c_temp = NULL;
}

void set_color(char color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void set_cursor(short x, short y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x, y });
}

void set_team(struct unit** players) {
	struct unit* teams = NULL;
	static char number_of_team = 0;
	do {
		printf("팀 수를 정하세요. (최대 10) ");
		scanf_s("%d", &number_of_team);
		team_num = number_of_team;
		teams = (struct unit*)calloc(number_of_team, sizeof(struct unit));
		*players = teams;
	} while (number_of_team < 2 && number_of_team < 11);

	for (char i = 0; i < number_of_team; i++) {
		char team_selected = 0;
		char cursor_pos = 1;

		system("cls");
		set_color(15);
		printf("팀 색을 정하세요.\n");
		for (char j = 1; j < 15; j++) {
			set_color(j);
			if (!sel_color[j])
				printf(" O");
			else
				printf(" X");
		}
		set_cursor(cursor_pos * 2 - 1, 2);
		set_color(15);
		printf("^");
		while (1) {
			char sel_cursor = move_cursor();
			set_cursor(0, 3);
			printf("                     ");

			set_cursor(cursor_pos * 2 - 1, 2);
			printf(" ");
			if (team_selected)
				break;
			if (sel_cursor == 1) {
				if (cursor_pos != 1)
					cursor_pos --;
			}
			else if (sel_cursor == 2) {
				if (cursor_pos != 14)
					cursor_pos ++;
			}
			else if (sel_cursor == 4) {
				if (!sel_color[cursor_pos]) {
					team_color[i] = cursor_pos;
					sel_color[cursor_pos] = 1;

					set_color(cursor_pos);
					set_cursor(cursor_pos * 2 - 1, 1);
					printf("X");

					(teams + i)->team = cursor_pos;

					break;
				}
				else {
					set_cursor(0, 3);
					printf("이미 선택된 팀입니다.");
				}
			}
			set_cursor(cursor_pos * 2 - 1, 2);
			printf("^");
			set_cursor(cursor_pos * 2 - 1, 2);
		}
	}
}

void set_unit(struct unit* players) {
	struct unit* teams = players;
	struct unit* prev = NULL, * p = NULL;
	for (int i = 0; i < team_num; i++) {
		int unit_num = 0;
		do {
			system("cls");
			set_cursor(0, 0);
			set_color(team_color[i]);
			// printf("%d", i + 1);
			set_color(15);
			// printf("번째 팀의 유닛 수를 정하시오. (1 ~ 16)" );
			// scanf_s("%d", &unit_num);
			unit_num = 1;
		} while (unit_num < 1 && unit_num>16);
		p = (teams + i);
		for (int j = 0; j < unit_num; j++) {
			p->unit_num = j;
			p->x = rand() % window_col_size;
			p->y = rand() % window_line_size;
			p->unit_type = '*';
			p->link = NULL;
			prev = p;
			if (j != unit_num) {
				p = (struct unit*)malloc(sizeof(struct unit));
				prev->link = p;
				p->team = prev->team;
			}
		}
	}
}

char move_cursor() {
	unsigned char key = 0;
	while (1) {
		if (_kbhit()) {
			key = _getch();
			if (key == 224 || key == 0) {
				key = _getch();
				switch (key) {
				case 72:
					return 0;
					break;
				case 75:
					return 1;
					break;
				case 77:
					return 2;
					break;
				case 80:
					return 3;
					break;
				default:
					;
				}
			}
			else {
				if (key == 13)
					return 4;
			}
		}
	}
}

void move_unit(struct unit* _unit, char dir) {
	set_cursor(_unit->x, _unit->y);
	printf(" ");
	if (_unit->y == 0 && dir == 0);
	else if (_unit->x == 0 && dir == 1);
	else if (_unit->x == window_col_size - 1 && dir == 2);
	else if (_unit->y == window_line_size - 1 && dir == 3);
	else if (dir > -1 && dir < 4) {
		_unit->x += direction[dir][0];
		_unit->y += direction[dir][1];
	}
	else
		fprintf(stderr, "%s", "not");
	set_cursor(_unit->x, _unit->y);

	set_color(_unit->team);
	printf("%c",_unit->unit_type);
}

void view_cursor(char state)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = state;
	ConsoleCursor.dwSize = 2;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}