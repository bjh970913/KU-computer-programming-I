#include<stdio.h>
#include"snake.h"

void main() {
	int ekey = 0;

	init();						// 변수값 초기화 함수
	draw();
	//sPrint(1 * 2, 1, "weaagreg");
	//draw();
	//return 0;

	while (1) {

		if (_kbhit()) {			// 키보드 입력이 있으면 1, 없으면 0을 리턴
			ekey = _getch();	// 입력받은 키 값을 받음
			_flushall();
			
			if (
				sn.head_direction == UP && ekey == D ||
				sn.head_direction == DOWN && ekey == U ||
				sn.head_direction == RIGHT && ekey == L ||
				sn.head_direction == LEFT && ekey == R
				)
				ekey = sn.head_direction;

			switch (ekey) {
			case L:
				sn.head_direction = LEFT;
				break;
			case R:
				sn.head_direction = RIGHT;
				break;
			case U:
				sn.head_direction = UP;
				break;
			case D:
				sn.head_direction = DOWN;
				break;
			}

		}
		update();				// 변수 업데이트
		draw();					// 화면에 출력

		if (!sn.alive)
		{
			sPrint(10, 10, "You loose!!");
			break;
		}
		else if(obj.prey_cnt == 0)
		{
			update();
			draw();
			sPrint(10, 10, "You win!!");
			break;
		}

		Sleep(50);
	}

	sFlipping();
	_getch();
	sRelease();
}

