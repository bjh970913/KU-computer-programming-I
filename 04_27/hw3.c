#include <stdio.h>

void strcat(char *s1, const char *s2);

int main(int argc, char const *argv[])
{
    char string1[80];
    char string2[80];

    printf("Enter two strings: ");
    scanf("%80s%80s", string1, string2);

    strcat(string1, string2);

    printf("%s\n", string1);

    return 0;
}

void strcat(char *s1, const char *s2)
{
    while(*s1 != 0)
    {
        s1++;
    }
    while(*s2 != 0)
    {
        *s1 = *s2;

        s1++;
        s2++;
    }
    *s1 = 0;

    return;
}