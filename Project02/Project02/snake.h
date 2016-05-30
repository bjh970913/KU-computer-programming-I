#pragma once
#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#include"screen.h"

#define ROW 20
#define COL 40

#define L 75
#define R 77
#define U 72
#define D 80

typedef enum _dir { LEFT, RIGHT, UP, DOWN } direction;
typedef enum _objtype { EMPTY, WALL, PREY, SN_HEAD, SN_BODY } objtype;

typedef struct _pos {
	int x;
	int y;
}pos;

typedef struct _object {
	int prey_cnt;
	objtype map[COL][ROW];
}object;

typedef struct _snake {
	int length;
	int alive;
	pos head, tail;
	direction head_direction;
}snake;


snake sn;
object obj;


void init();
void update();
void draw();
void release();

void checkForward(pos front);
void goForward(pos front);

#endif