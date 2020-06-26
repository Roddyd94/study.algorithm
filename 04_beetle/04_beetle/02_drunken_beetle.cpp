#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROW 5
#define COL 7

typedef struct Beetle {
	int x;
	int y;
}Beetle;

int main() {
	int tiles[ROW][COL] = { 0 };
	const int dirs[8][2] = {
		{0,-1},
		{1,-1},
		{1,0},
		{1,1},
		{0,1},
		{-1,1},
		{-1,0},
		{-1,-1}
	};
	int row = sizeof(tiles) / sizeof(tiles[0]);
	int col = sizeof(tiles[0]) / sizeof(tiles[0][0]);
	char tile_c[3] = { '.','*','B' };
	int blank = 0;
	Beetle beetle = { ROW / 2,COL / 2 };
	int cnt = 0;
	int dir = 0;

	srand((unsigned int)time(NULL));

	do{
		blank = 0;

		system("cls");
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int sw = tiles[i][j];
				if (i == beetle.y && j == beetle.x) {
					tiles[i][j] = 1;
					printf("%2c", tile_c[2]);
					sw = 1;
				}
				else {
					printf("%2c", tile_c[sw]);
				}
				if (!sw) blank++;

			}
			printf("\n");
		}
		printf("dir: %d, count: %d", dir, cnt);
		Sleep(10);
		if (!blank) break;

		dir = rand() % 8;
		if (beetle.x == 0 && dirs[dir][0] == -1)continue;
		if (beetle.x == col - 1 && dirs[dir][0] == 1)continue;
		if (beetle.y == 0 && dirs[dir][1] == -1)continue;
		if (beetle.y == row - 1 && dirs[dir][1] == 1)continue;
		beetle.x += dirs[dir][0];
		beetle.y += dirs[dir][1];
		cnt++;
	}while (1);
}

