#pragma once

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <conio.h>
#include <Windows.h>

#endif

#ifndef __STD_H__
#define __STD_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif

#ifndef __TIME_H__
#define __TIME_H__

#include <time.h>

#endif

enum COLOR
{
	BLACK, DARK_BLUE, DARK_GREEN, DARK_CYAN,
	DARK_RED, DARK_MAGENTA, DARK_YELLOW, LIGHT_GREY,
	GREY, BLUE, GREEN, CYAN,
	RED, MAGENTA, YELLOW, WHITE
};

enum KEY
{
	UP = 1, DOWN, LEFT, RIGHT, ENTER, SPACE, ESC
};

#define K_UP	72
#define K_DOWN	80
#define K_LEFT	75
#define K_RIGHT	77
#define K_ENTER	13
#define K_SPACE	32
#define K_ESC	27

#define SCREEN_WIDTH	64
#define SCREEN_HEIGHT	20

void set_pos(short x, short y); 
void set_color(char color, char bgcolor);
void set_screen(short width, short height, WCHAR* title);
COORD get_pos();
void set_cursor(char state);
void init_rand();
char get_key();