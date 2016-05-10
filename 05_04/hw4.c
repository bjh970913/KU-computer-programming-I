#include <stdio.h>
#include <string.h>

#define NUMBER 10

int main(int argc, char const *argv[])
{
    char strings[NUMBER][30] = {0};
    char tmp[30];
    int i, j;

    for(i=0;i<NUMBER;i++)
    {
        printf("Enter a string: ");
        gets(strings[i]);
    }

    for(i=1;i<NUMBER;i++)
    {
        for(j=0;j<NUMBER-i;j++)
        {
            if(strcmp(strings[j], strings[j+1])>0)
            {
                strcpy(tmp, strings[j]);
                strcpy(strings[j], strings[j+1]);
                strcpy(strings[j+1], tmp);
            }
        }
    }

    printf("\nThe strings in sorted order are:\n");
    for(i=0;i<NUMBER;i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}