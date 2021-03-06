#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wordutility
{
    char word[20];
    int count;
    int isWritten;
};

struct WORD_DATA
{
    struct wordutility data;
    struct WORD_DATA *next;
}typedef word_data;

char space[] = " ";

void add(word_data *data, char *str)
{
    word_data *next = data, *tmp;
    char *str_tmp;
    
    while(1)
    {
        if(strcmp(str, next->data.word) == 0)
        {
            next->data.count++;
            break;
        }
        else
        {
            if(next->next == NULL)
            {
                tmp = (word_data *)malloc(sizeof(word_data));
                
                strcpy(tmp->data.word, space);
                tmp->data.count = 0;
                tmp->next = NULL;
                
                strcpy(next->data.word, str);
                next->data.count = 1;
                next->next = tmp;
                break;
            }
            next = next->next;
        }
    }
}

void print(word_data *data)
{
    word_data *next = data;
    
    while(1)
    {
        if(next->next == NULL)
        {
            break;
        }

        printf("\"%s\" appeared %d time%s\n", next->data.word, next->data.count, (next->data.count==1)?"":"s");
        next = next->next;
    }
}

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
    int i;
    char buff[99999];
    char token[256-1-26-26];
    char *p;
    word_data *data = (word_data *)malloc(sizeof(word_data));
    
    strcpy(data->data.word, space);
    data->next = NULL;
    data->data.count = 0;
    
    set_tocken(token);
    
    printf("Enter three lines of text:\n");
    for(i=0; i<3; i++)
    {
        gets(buff);
        p = strtok(buff, token);
        while(p)
        {
            add(data, p);
            p = (char*)(strtok(NULL, token));
        }
    }

    printf("\n");
    print(data);
    
    return 0;
}