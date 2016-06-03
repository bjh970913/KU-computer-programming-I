#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    int key, tmp, tmp2;
    node *stack = NULL, *tmp_node1, *tmp_node2;

    printf(
        "Enter your choice\n"
        "\t1 to push a value on the stack.\n"
        "\t2 to pop a value off the stack.\n"
        "\t3 to end.\n"
    );

    printf("? ");
    scanf("%c", &key);
    while(key!=3)
    {
        switch(key)
        {
            case '1':
                printf("Enter a integer: ");
                scanf(" %d", &tmp);

                push(&stack, tmp);

                break;
            case '2':
                tmp = pop(&stack);
                printf("The poped value is %d.\n", tmp);
                break;
            case '3':
                goto end;
                break;
            default:
                getchar();
        }

        printf("The stack is :\n");
        printNodes(stack, "%d%s", " --> ", "NULL");
notFound:
        printf("\n? ");
        scanf(" %c", &key);
    }
end:
    printf("End of run.\n");
    destroyNodes(stack);
    return 0;
}