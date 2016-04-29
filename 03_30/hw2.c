#include <stdio.h>
#include <math.h>

void isPerfect(int a);

int main(int argc, char const *argv[])
{
    int i;

    for (i = 1; i < 1000; ++i)
    {
        isPerfect(i);
    }
    return 0;
}

void isPerfect(int a)
{
    int i, sum=0;
    for (i = 1; i < a; i++)
    {
        sum += (a%i==0)?i:0;
    }
    if(sum==a)
    {
        printf("%d is perfect\n", a);
    }
}