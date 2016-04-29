#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i, j, x;

    for (i=-4; i<=4 ; ++i)
    {
        x = (i<0)?i*-1:i;

        for(j=0; j<x; j++){
            printf(" ");
        }
        for(j=0; j<(5-x)*2-1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}