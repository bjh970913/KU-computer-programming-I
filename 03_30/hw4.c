#include <stdio.h>
#include <math.h>

int reverse(int a);

int main(int argc, char const *argv[])
{
    int input;
    printf("Enter a number beTween 1 and 9999: ");
    scanf("%d", &input);

    printf("The number with its digits reverseed is: %d\n", reverse(input));
    return 0;
}

int reverse(int a)
{
    int ret = 0;
    while(a!=0)
    {
        ret *= 10;
        ret += a%10;
        a /= 10;
    }
    return ret;
}