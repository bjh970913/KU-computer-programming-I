#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int freq[26] = {0, }, i, c;
    char buff[100], *buff_p;
    printf("Enter three lines of text:\n");

    for(i=0;i<3;i++)
    {
        gets(buff);
        for(c=0;c<strlen(buff);c++)
        {
            buff[c] = tolower(buff[c]);    
        }
        
        for(c=0;c<26;c++)
        {
            buff_p = buff;
            
            buff_p = strchr(buff_p, c+97);
            while(buff_p != NULL)
            {
                freq[c]++;
                *buff_p -= 32;
                buff_p = strchr(buff, c+97);
            }
        }
    }

    for(c=0;c<26;c++)
    {
        printf("%c:  %4d\n", c+97, freq[c]);
    }

    return 0;
}