#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    int tmp1;
    node *list1, *list1_ref;
    node *list2, *list2_ref;
    node *list_merged = NULL;

    push(&list1, 10);
    push(&list1, 8);
    push(&list1, 6);
    push(&list1, 4);
    push(&list1, 2);
    list1_ref = list1;

    push(&list2, 9);
    push(&list2, 7);
    push(&list2, 5);
    push(&list2, 3);
    push(&list2, 1);
    list2_ref = list2;

    printf("List 1 is: ");
    printNodes(list1, "%d%s", " ", "*");
    printf("\nList 2 is: ");
    printNodes(list2, "%d%s", " ", "*");

    while(list1_ref->next != list1 || list2_ref != list2)
    {
        if(list1_ref->data <= list2_ref->data)
        {
            tmp1 = list1_ref->data;
            list1_ref = list1_ref->next;
        }
        else
        {
            tmp1 = list2_ref->data;
            list2_ref = list2_ref->next;   
        }

        prepend(&list_merged, tmp1);
    }
    prepend(&list_merged, list1_ref->data);

    printf("\nThe merged list is: ");
    printNodes(list_merged, "%d%s", " ", "*");
    printf("\n");

    destroyNodes(list1);
    destroyNodes(list2);
    destroyNodes(list_merged);
    return 0;
}