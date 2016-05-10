#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i, sum=0;
    char buff[10];
    for(i=0;i<4;i++)
    {
        printf("Enter an interger string: ");
        gets(buff);
        sum += atoi(buff);
    }

    printf("\nThe total of the values is %d\n", sum);
    return 0;
}