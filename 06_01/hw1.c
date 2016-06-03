#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    int key, tmp, tmp2;
    node *character = NULL, *tmp_node1, *tmp_node2;

    printf(
        "Enter your choice\n"
        "\t1 to insert an element into the list.\n"
        "\t2 to delete an element from the list.\n"
        "\t3 to end.\n"
    );

    printf("? ");
    scanf("%c", &key);
    while(key!=3)
    {
        switch(key)
        {
            case '1':
                printf("Enter a character: ");
                scanf(" %c", &tmp);
                printf("value: %c\n", tmp);

                if(character == NULL)
                {
                    character = createNode();
                    character->data = tmp;
                }
                else
                {
                    tmp_node1 = character;
                    while(tmp_node1->next != character)
                    {
                        if(tmp_node1->data <= tmp && tmp <= tmp_node1->next->data)
                        {
                            break;
                        }
                        tmp_node1 = tmp_node1->next;
                    }
                    if(tmp_node1->next == character)
                    {
                        if(tmp_node1->data > tmp)
                        {
                            tmp2 = tmp_node1->data;
                            tmp_node1->data = tmp;
                            tmp = tmp2;
                        }
                    }

                    tmp_node2 = createNode();
                    tmp_node2->data = tmp;
                    
                    tmp_node1->next->prev = tmp_node2;
                    tmp_node2->next = tmp_node1->next;

                    tmp_node1->next = tmp_node2;
                    tmp_node2->prev = tmp_node1;
                }

                break;
            case '2':
                printf("Enter character to be deleted: ");
                scanf(" %c", &tmp);

                tmp_node1 = character;
                while(tmp_node1->next != character)
                {
                    if(tmp_node1->data == tmp)
                    {
                        break;
                    }
                    tmp_node1 = tmp_node1->next;
                }

                if(tmp_node1->data == tmp)
                {
                    tmp_node1->next->prev = tmp_node1->prev;
                    tmp_node1->prev->next = tmp_node1->next;
                    free(tmp_node1);
                    printf("%c deleted.\n", tmp);
                }
                else
                {
                    printf("%c not found.\n", tmp);
                    goto notFound;
                }
                break;
            case '3':
                goto end;
                break;
        }

        printf("The list is :\n");
        printNodes(character, "%c%s", " --> ", "NULL");
notFound:
        printf("\n? ");
        scanf(" %c", &key);
    }
end:
    printf("End of run.\n");
    destroyNodes(character);
    return 0;
}