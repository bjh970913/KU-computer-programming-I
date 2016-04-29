#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

#define oneSec 1000
#define halfSec 500

int getSelection();
int doAction(int select);
int getNumber();
void printState();
void doGame();

struct state
{
    int cash;
    int win;
    int lose;
};

struct state stat;

char *hand[] = { "Rock", "Scissors", "Paper", "????" };

int main(int argc, char const *argv[])
{
    int select = 0;
    stat.cash = 1000000;
    stat.win = 0;
    stat.lose = 0;
    srand(time(NULL));

    do
    {
        select = getSelection();
        doAction(select);
    } while (1 <= select && select <= 2);

    return 0;
}

int getNumber() 
{
    char buff[100] = {0,};
    char *buff_p = buff;
    fgets(buff, 100, stdin);
    fflush(stdin);
    do {
        if (*buff_p != '\n' && *buff_p < '0' || '9' < *buff_p)
        {
            if (buff[98]!=0 && buff[98]!='\n')
            {
                while (getchar() != '\n');
            }
            return -1;
        }
    } while (*(++buff_p) != 0);
    
    return atoi(buff);
}

int getSelection()
{
    int input = -1;
    system("cls");
    printf(
        "-------------------------------------\n"
        "\t1. My State\n"
        "\t2. RSP\n"
        "\t3. End\n"
        "-------------------------------------\n"
    );

    do
    {
        printf("\tEnter the number: ");
        input = getNumber();
    } while (input<1 || 3<input);

    return input;
}

int doAction(int select)
{
    switch (select)
    {
    case 1:
        printState();
        break;
    case 2:
        doGame();
        break;
    }
    return 0;
}

void printState()
{
    system("cls");
    printf(
        "-------------------------------------\n"
        "\tUser's State\n"
        "\tCash: %d won\n"
        "\tWin: %d\n"
        "\tLose: %d\n"
        "-------------------------------------\n"
        "Please Enter any key to return"
        , stat.cash, stat.win, stat.lose
    );
    _getch();
    return;
}

void doGame()
{
    int bet;
    int computer, player;

    system("cls");
    printf(
        "-------------------------------------\n"
        "\tRock Scissors Paper\n"
        "-------------------------------------\n"
        "\tCash: %d\n"
        "\tHow much do you want ot bet?\n"
        , stat.cash
    );
    do
    {
        printf("\t:");
        bet = getNumber();
    } while (1>bet || bet>stat.cash);
    printf(
        "\tOK\n"
        "\t..then Now start!\n"
    );
    _getch();
    system("cls");

restart:
    printf(
        "-------------------------------------\n"
        "\tRock Scissors Paper\n"
        "\n"
        "\tStart?\n"
        "-------------------------------------\n"
    );
    _getch();

    printf("\t3...\n");
    Sleep(oneSec);
    printf("\t2..\n");
    Sleep(oneSec);
    printf("\t1.\n");
    Sleep(oneSec);

    printf("\trock, ");
    Sleep(halfSec);
    printf("\tscissors, ");
    Sleep(halfSec);
    printf("\tpaper!\n");
    Sleep(halfSec);

    if (!_kbhit())
    {
        printf(
            "\tDoes not Enter any key\n"
        );
        bet *= -1;
    }
    else
    {
        player = _getch();
        switch (player)
        {
            case 'q':
                player = 0;
                break;
            case 'w':
                player = 1;
                break;
            case 'e':
                player = 2;
                break;
            default:
                player = 3;
        }
        computer = rand() % 3;

        printf("\tUser: %s\t\tComputer: %s\n", hand[player], hand[computer]);
        if (player == computer)
        {
            printf("\tDraw!\n\tRestart\n");
            goto restart;
        }
        else if (player == 3)
        {
            printf(
                "\tI can't understan your choice!!\n"
                "\tUse your hand plz.....\n"
            );
            bet *= -1;
        }
        else if (player == (computer + 1) % 3)
        {
            bet *= -1;
        }
    }

    if (bet > 0)
    {
        stat.win++;
        printf("\t%s%d\n\n", "Win!\n+", bet);
    }
    else 
    {
        stat.lose++;
        printf("\t%s%d\n\n", "Lose!\n", bet);
    }
    
    stat.cash += bet;

    if (!stat.cash)
    {
        printf("\tDude... your bankrupted... Go home. go...\n\n");
        exit(0);
    }

    printf(
        "\tCash: %d\n"
        "\tOne more?\n"
        "\t1. yes\n"
        "\t2. no\n"
        , stat.cash
    );
    bet = -1;
    do
    {
        printf("\t:");
        bet = getNumber();
    } while (1>bet || bet>2);

    if (bet == 1)
    {
        doGame();
    }
}