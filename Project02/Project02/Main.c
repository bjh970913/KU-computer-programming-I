#include<stdio.h>
#include"snake.h"

void main() {
	int ekey = 0;
	
	init();						// ������ �ʱ�ȭ �Լ�
	
	while (1) {

		if (_kbhit()) {			// Ű���� �Է��� ������ 1, ������ 0�� ����
			ekey = _getch();	// �Է¹��� Ű ���� ����
			_flushall();
			
			switch (ekey) {
			case L:				
				break;
			case R:				
				break;
			case U:				
				break;
			case D:				
				break;
			default:
				
			}

		}
		update();				// ���� ������Ʈ
		draw();					// ȭ�鿡 ���

		Sleep(50);
	}
	release();
}

