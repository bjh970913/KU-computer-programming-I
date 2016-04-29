#include <stdio.h>

int main(int argc, char const *argv[])
{
    int b0, b1, b2, b3;
    int i;
    printf("Demical\t\tBinary\n");
    for(i=0; i<16; i++){
        b0 = ((i%16)/8)?1:0;
        b1 = ((i%8)/4)?1:0;
        b2 = ((i%4)/2)?1:0;
        b3 = ((i%2)/1)?1:0;

        printf("%d\t\t\t%d%d%d%d\n", i, b0, b1, b2, b3);
    }

    return 0;
}