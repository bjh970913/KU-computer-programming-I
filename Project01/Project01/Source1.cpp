#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

void mainmenu();
int input(int sum);
void slash(int temp, int i);
void mystate();
void rsp_betting();
void rsp_game(int betting);

char username[100];
int money = 1000000, win = 0, lose = 0;


int main(void) {
	srand(time(NULL));

	printf("\n\tWhat is your username?: ");
	//gets(username);
	//printf("\n\tYour name is %s.", username); Sleep(2000);

	mainmenu();

	system("pause > NULL");
	return 0;
}

void mainmenu() {
	int number;
	system("cls");

	slash(1, 38);
	printf("\t  Welcome to Rock Scissor Paper Game!");
	slash(1, 38);
	printf("\n\t\t1. My State\n\t\t2. RSP Game\n\t\t3. End\n");
	slash(1, 38);

	do {
		printf("\n\t   Enter the number: ");
		number = input(0);
	} while ((number + 2) / 3 != 1); // number != 1 && number != 2 && number != 3

	switch (number) {
	case 1: mystate();
		break;
	case 2: rsp_betting();
		break;
	case 3:
		system("cls");
		printf("\n\tBye, %s! See you later~\n", username);
	}
}

int input(int sum) {

	int i = getchar() - '0';
	if (i == '\n' - '0') return sum;
	if ((i + 10) / 10 != 1) {
		while (getchar() != '\n');
		return -1;
	}

	return input(sum * 10 + i);
}


void slash(int temp, int i) {
	int count;

	printf("\n");
	for (count = 0; count < temp; count++)
		printf("\t");
	for (count = 0; count < i; count++)
		printf("-");
	printf("\n");
}


void mystate() {
	system("cls");
	slash(1, 37);
	printf("\n\t\t%s's State\n", username);
	printf("\t\tCash: %d won\n", money);
	printf("\t\tWin: %d\n", win);
	printf("\t\tLose: %d\n", lose);
	slash(1, 37);
	printf("\n\t   Please enter any key to return.");
	while (1)
		if (_kbhit()) break;
	while (getchar() != '\n');

	mainmenu();
}


void rsp_betting() {
	int betting;
	system("cls");

	printf("\n\tYour cash: %d\n", money);
	printf("\tHow many money do you want to bet?  ");
	do {
		betting = input(0);
		if (betting <= 0) printf("\tError! You can't bet negative, zero value or character.  ");
		else if (betting > money) printf("\tError! You bet more money than yours.  ");
		else break;
	} while (1);

	rsp_game(betting);
}


void rsp_game(int betting) {
	int choice, com, number;
	char RSP[4][9] = { "Rock", "Scissors", "Paper", "None" };
	system("cls");

	slash(1, 37);
	printf("\n\tLet's Play game!\n\n");
	printf("\tKeyboard Button\n");
	printf("\tRock: 1 / Scissor: 2 / Paper: 3\n");
	printf("\t If you don't enter anything \n\t   in these three things, you lose.\n");
	slash(1, 37);
	printf("\n\t   Enter any key to start game.");
	while (1) {
		if (_kbhit()) {
			while (getchar() != '\n');
			break;
		}
	}

	printf("\n\t  3...\n"); Sleep(1000);
	printf("\t  2..\n"); Sleep(1000);
	printf("\t  1.\n"); Sleep(1000);
	printf("\t  Rocks  "); Sleep(500);
	printf("Scissors  "); Sleep(500);
	printf("Paper!\n"); Sleep(500);

	if (_kbhit()) {
		choice = _getch() - 49; // Rock = '1' - 49 = 0, Scissor = '2' - 49 = 1, Paper = '3' - 49 = 2
		if ((choice + 3) / 3 != 1) choice = 103;
	}
	else choice = 203; // 103과 203은, 4로 나누었을 때 3이 남는 수를 임의로 정한 것이다.


	com = rand() % 3;
	slash(1, 37);
	printf("\n\t%s: %s\t Com: %s\n", username, RSP[choice % 4], RSP[com]); // None을 출력하기 위해서 4로 나눈다.


	switch (choice <= 2 ? (choice - com + 3) % 3 : choice) { // 3을 더해준 이유는 -1 % 3 = -1이기 때문이다.
	case 0: printf("\tDraw!\n");
		break;
	case 1: lose++;
		money -= betting;
		printf("\tYou lose!\n\t-%d\n", betting);
		break;
	case 2: win++;
		money += betting;
		printf("\tYou win!\n\t+%d\n", betting);
		break;
	case 103: lose++;
		money -= betting;
		printf("\tYou enter other key. You lose!\n\t-%d\n", betting);
		break;
	case 203: lose++;
		money -= betting;
		printf("\tYou don't enter any key. You lose!\n\t-%d\n", betting);
	}

	printf("\tCash: %d\n", money); Sleep(1000);
	while (getchar() != '\n');


	if (money < betting) {
		if (money == 0) {
			printf("\n\tYou have no money...\n");
			printf("\t%s, good bye! See you later~!\n", username);
			return;
		}

		printf("\n\tYour betting money is more than your possesion.\n");
		printf("\n\tWhat do you want to do?\n");
		printf("\t1: Change betting money.\n");
		printf("\t2: Go to main menu.\n");

		do {
			printf("\n\t Enter the number: ");
			number = input(0);
		} while ((number++ + 1) / 2 != 1);
	}

	else {
		printf("\n\tWhat do you want to do?\n");
		printf("\t1: Restart this game!\n");
		printf("\t2: Change betting money.\n");
		printf("\t3: Go to main menu.\n");

		do {
			printf("\n\t Enter the number: ");
			number = input(0);
		} while ((number + 2) / 3 != 1);
	}

	switch (number) {
	case 1: rsp_game(betting);
		break;
	case 2: rsp_betting();
		break;
	case 3:
		mainmenu();
	}
}