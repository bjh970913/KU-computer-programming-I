#include <stdio.h>

int hanoi(int num, int from, int to, int temp);

int main(int argc, char const *argv[])
{
    int num;
    printf("Enter the starting number of disks: ");
    scanf("%d", &num);

    hanoi(num, 1, 3, 2);

    return 0;
}

int hanoi(int num, int from, int to, int temp)
{
    if (num==1)
    {
        printf("%d -> %d\n", from, to);
        return 0;
    }
    else
    {
        hanoi(num-1, from, temp, to);
        printf("%d -> %d\n", from, to);
        hanoi(num-1, temp, to, from);
        return 0;
    }
}