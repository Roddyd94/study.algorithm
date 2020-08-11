#pragma once

#ifndef __UTIL_H__
#define __UTIL_H__

#include "util.h"

#endif

#ifndef __STD_H__
#define __STD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif

enum ENTITY { WALL, FLOOR, PLAYER, GOAL, DOOR, KEY };

typedef struct stage
{
	COORD stage_size;
	char* map;
} STAGE;

void draw_title();
void draw_menu();
char select_menu();
char select_stage();
char start_stage(char stage);
void set_icon(char entity);
void show_info();
char check_tile(char tile, char* keys);