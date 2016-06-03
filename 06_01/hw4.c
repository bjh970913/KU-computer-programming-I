#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    int tmp1;
    node *list = NULL, *reverse = NULL;
    
    prepend(&list, 'A');
    prepend(&list, 'B');
    prepend(&list, 'C');
    prepend(&list, 'D');
    prepend(&list, 'E');
    prepend(&list, 'F');
    prepend(&list, 'G');
    prepend(&list, 'H');
    prepend(&list, 'I');
    prepend(&list, 'J');

    printf("The list is: \n");
    printNodes(list, "%c%s", " ", "*");
    printf("\n");

    while(tmp1 = pop(&list))
    {
        push(&reverse, tmp1);
    }

    printf("The list in reverse is: \n");
    printNodes(reverse, "%c%s", " ", "*");
    printf("\n");

    destroyNodes(list);
    return 0;
}