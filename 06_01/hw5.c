#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    char tmp, tmp2, flag;
    node *plain, *string, *reverse;

    printf("Enter a line of text:\n");

    while(tmp = getchar())
    {
        if(tmp == '\n')
            break;
        if(('a' <= tmp && tmp <= 'z') || 
           ('A' <= tmp && tmp <= 'Z') || 
           ('0' <= tmp && tmp <= '9'))
        {
            prepend(&plain, tmp);
            push(&reverse, tmp);
        }
        prepend(&string, tmp);
    }
    
    flag = 0;
    while(1)
    {
        tmp = pop(&plain);
        tmp2 = pop(&reverse);

        if(!tmp || !tmp2)
            break;
        if(tmp != tmp2)
        {
            flag = 1;
            break;
        }
    }

    printf("\"");
    printNodes(string, "%c%s", "", "");
    printf("\" is %sa palindrome.\n", (flag==0)?"":"not ");

    destroyNodes(plain);
    destroyNodes(reverse);
    return 0;
}