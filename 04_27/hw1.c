#include <stdio.h>

void func(int *a, int *b, int *c);

int main(int argc, char const *argv[])
{
    int a, b, c;

    printf("Enter three numbers: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("Before: a = %d, b = %d, c = %d\n", a, b, c);

    calc(&a, &b, &c);

    printf("After: a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}

void func(int *a, int *b, int *c)
{
    int tmp;

    *a += 1;

    tmp = *c;
    *c *= *b;
    *b = tmp;

    return;
}