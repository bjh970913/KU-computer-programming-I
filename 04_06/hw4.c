#include <stdio.h>

void stringReverse( char strArray[] );

int main(int argc, char const *argv[])
{
    char strArray[30] = "Print this string backward.";

    printf("%s\n", strArray);
    stringReverse(strArray);
    printf("\n");

    return 0;
}

void stringReverse( char strArray[] )
{
    if(strArray[0]!=0)
    {
        stringReverse(strArray+1);
        putchar(strArray[0]);
    }
}