#include <stdio.h>
#include <math.h>

int ulcase(char a);

int main(int argc, char const *argv[])
{
    char input;
    printf("Enter the racter: ");
    input = getchar();
    printf("%c: %s\n", input, ulcase(input) == 1 ? "uppercase" : "lowercase");
    return 0;
}

int ulcase(char a)
{
    return ('A'<=a&&a<='Z');
}