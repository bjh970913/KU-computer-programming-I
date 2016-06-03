#include"snake.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init() {
	sInit();

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			obj.map[i][j] = EMPTY;
		}
	}

	for (int i = 0; i < COL; i++)
	{
		obj.map[i][0] = WALL;
		obj.map[i][ROW - 1] = WALL;
	}
	for (int i = 1; i < ROW - 1; i++)
	{
		obj.map[0][i] = WALL;
		obj.map[COL - 1][i] = WALL;
	}

	srand(time(NULL));
	int tmp_x = rand() % 26 + 7;
	int tmp_y = rand() % 6 + 7;

	sn.head.x = tmp_x;
	sn.head.y = tmp_y;
	
	sn.tail.x = tmp_x;
	sn.tail.y = tmp_y;
	
	sn.alive = 1;
	obj.map[tmp_x][tmp_y] = SN_HEAD;
	sn.length = 1;
	sn.length_aim = 6;
	
	sn.head_direction = rand() % 4;
	
	int num;
	printf("Enter the number of items: ");
	scanf_s("%d", &num);

	obj.prey_cnt = num;
	while (num != 0)
	{
		tmp_x = rand() % 38 + 1;
		tmp_y = rand() % 18 + 1;

		if (obj.map[tmp_x][tmp_y] == EMPTY)
		{
			obj.map[tmp_x][tmp_y] = PREY;
			num--;
		}
	}
}

void update() {
	pos tmp;
	tmp = sn.head;
	
	switch (sn.head_direction)
	{
	case LEFT:
		tmp.x--;
		break;
	case RIGHT:
		tmp.x++;
		break;
	case UP:
		tmp.y--;
		break;
	case DOWN:
		tmp.y++;
		break;
	}

	checkForward(tmp);
	//collision
}

void checkForward(pos front)
{
	int next = obj.map[front.x][front.y];
	
	if ( next != WALL)
	{
		if (next == SN_BODY)
		{
			sn.alive = 0;
		}
		else
		{
			if (next == PREY)
			{
				obj.prey_cnt--;
				sn.length_aim++;
			}

			goForward(front);
		}
	}
}

void goForward(pos front)
{
	int x, y;
	x = front.x;
	y = front.y;
	obj.map[x][y] = SN_HEAD;
	
	obj.map[sn.head.x][sn.head.y] = SN_BODY;
	sn.head = front;
	if(sn.length_aim == sn.length)
	{
		x = sn.tail.x;
		y = sn.tail.y;

		obj.map[x][y] = EMPTY;
		if (obj.map[x-1][y] == SN_BODY)
		{
			sn.tail.x = x - 1;
		}
		else if (obj.map[x+1][y] == SN_BODY)
		{
			sn.tail.x = x + 1;
		}
		else if (obj.map[x][y-1] == SN_BODY)
		{
			sn.tail.y = y - 1;
		}
		else if (obj.map[x][y+1] == SN_BODY)
		{
			sn.tail.y = y + 1;
		}
	}
	else
	{
		sn.length++;
	}
}



void draw() {
	int x = 30, y = 20;

	sClear();

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			switch (obj.map[j][i])
			{
			case WALL:
				sPrint(j*2, i, "■");
				//printf("a");
				break;
			case PREY:
				sPrint(j*2, i, "♥");
				//printf("b");
				break;
			case SN_HEAD:
				sPrint(j*2, i, "◎");
				//printf("c");
				break;
			case SN_BODY:
				sPrint(j*2, i, "◈");
				//printf("d");
				break;
			}
		}
	}


	sFlipping();
}

void release() {
	sRelease();
}

