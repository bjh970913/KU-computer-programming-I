#include <stdio.h>
#include <string.h>

void print_bin(int number)
{
    int i;
    printf("\t%6d = ", number);

    for(i=15; i>=8; i--)
    {
        printf("%d", (number>>i) % 2);
    }
    printf(" ");
    for(i=7; i>=0; i--)
    {
        printf("%d", (number>>i) % 2);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int in, tmp, i;

    printf("Enter an unsigned integer: ");
    scanf("%d", &in);

    printf("Brfore bits are reversed:\n");
    print_bin(in);

    tmp = 0;
    for(i=0;i<16;i++)
    {
        tmp = tmp<<1;
        tmp += in % 2;
        in = in>>1;
    }
    in = tmp;

    printf("After bits are reversed:\n");
    print_bin(in);
}