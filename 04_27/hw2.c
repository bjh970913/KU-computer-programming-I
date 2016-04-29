#include <stdio.h>

int strcmp(const char *s1, const char *s2);

int main(int argc, char const *argv[])
{
    char string1[80];
    char string2[80];

    printf("Enter two strings: ");
    scanf("%80s%80s", string1, string2);

    printf("%s and %s are %s.\n", string1, string2, strcmp(string1, string2)?"equal":"not equal");

    return 0;
}

int strcmp(const char *s1, const char *s2)
{
    while(*s1 != 0 && *s2 != 0)
    {
        if(*s1 == *s2)
        {
            s1++;
            s2++;
        }
        else{
            return 0;
        }
    }
    if(((*s1==0) ^ (*s2==0)) == 1)
    {
        return 0;
    }
    return 1;
}