#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int main(int argc, char const *argv[])
{
    int arr[SIZE], i;
    srand(time(NULL));
    for(i=0;i<SIZE;i++)
    {
        arr[i] = rand()%100;
    }

    printf("Correct order:\n");
    for(i=0;i<SIZE;i++)
    {
        printf("%d  ", *(arr+i));
    }
    printf("\n");

    printf("Reverse order:\n");
    for(i=SIZE-1;i>-1;i--)
    {
        printf("%d  ", *(arr+i));
    }
    printf("\n");

    return 0;
}