#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input, max, index=0;

    scanf("%d", &input);
    max = input;
    index++;

    do{
        scanf("%d", &input);
        if(input>max){
            max = input;     
        }
        index++;
    }while(index < 5);

    printf("Largest is %d\n", max);

    return 0;
}