#include <stdio.h>
#include <string.h>

void set_tocken(char token[])
{
    int i,j;
    j = 0;
    for(i=1; i<65; i++)
    {
        token[j] = i;
        j++;
    }
    for(i=65+26; i<97; i++)
    {
        token[j] = i;
        j++;
    }
    for(i=97+26; i<256; i++)
    {
        token[j] = i;
        j++;
    }
}

int main(int argc, char const *argv[])
{
    char token[256-1-26-26], buff[100];
    char *p;
    int freq[50] = {0};
    int i;

    set_tocken(token);

    printf("Enter Three Lines of text:\n");
    for(i=0;i<3;i++)
    {
        gets(buff);
        p = strtok(buff, token);
        while(p)
        {
            // printf("%s\n", p);
            freq[strlen(p)]++;
            p = (char*)(strtok(NULL, token));
        }
    }
    printf("\n");
    for (i = 1; i < 50; i++)
    {
        if(freq[i])
        {
            printf("%d word of length %d\n", freq[i], i);
        }
    }

    return 0;
}