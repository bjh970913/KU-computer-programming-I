#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int base, exponent;

    do{
        printf("Enter the base number: ");
        scanf("%d", &base);
    }while(base<0);

    do{
        printf("Enter the exponent number: ");
        scanf("%d", &exponent);
    }while(exponent<0);

    printf("%d^%d is %d\n", base, exponent, (int)pow((double)base, (double)exponent));

    return 0;
}