#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip();
unsigned long long rdtsc(){
    asm("rdtsc");
}
int main(int argc, char const *argv[])
{
    int s,e;
    s = rdtsc();
    int i, j, result;
    int re[2] = {0,};
    srand(time(NULL));

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            result = flip();
            re[result]++;
            printf("%s ", result?"heads":"tails");
        }
        printf("\n");
    }

    printf("The total number of Heads was %d\n", re[1]);
    printf("The total number of Tails was %d\n", re[0]);
    e = rdtsc();

    printf("%d %d %d \n", e, s, e-s);
    return 0;
}

int flip()
{
    return rand()%2;
}