#include <stdio.h>
#include <math.h>

void print_bin(int number)
{
    int i;
    printf("\t%4d = ", number);

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
    int n, p, r;
    printf("Enter two integers: ");
    scanf("%d%d", &n, &p);

    printf("number:\n");
    print_bin(n);

    printf("pow:\n");
    print_bin(p);

    r = n * pow(2, p);
    printf("%d * 2^%d = %d\n", n, p, r);
    print_bin(r);

    // printf("pow:\n");
    // printf("n:\n");

    return 0;
}