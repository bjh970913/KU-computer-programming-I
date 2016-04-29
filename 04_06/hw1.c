#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int val[20]={0,}, i, r;
    bool check[20] = {0, };

    srand(time(NULL));

    printf("Nonrepetitive array vlaues are:\n");
    for(i=0;i<20;i++)
    {
        r = rand()%20;
        if(check[r]!=0)
        {
            break;
        }
        val[i] = r;
        check[r] = 1;
        printf("Arrary[ %d ] = %d\n", i, r);
    }

    return 0;
}