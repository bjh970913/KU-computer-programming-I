#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

int main(int argc, char const *argv[])
{
    int (*func[3])(int, int) = {add, sub, mul};
    char operator_d[3] = {'+', '-', '*'};
    size_t select;
    int n1, n2;
    int result;

    while(1)
    {
        printf(
            "0.Addition\n"
            "1.Subtraction\n"
            "2.ultiplication\n"
            "3.End\n"
            "Select the operation: "
        );
        scanf("%zd", &select);

        if(select>=3)
        {
            printf("Exit\n");
            return 0;
        }

        printf("Enter the two numbers: ");
        scanf("%d%d", &n1, &n2);

        result = (func[select])(n1, n2);
        printf("\n\t%d %c %d = %d \n\n", n1, operator_d[select], n2, result);
    }

    return 0;
}

int add(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mul(int a, int b)
{
    return a * b;
}