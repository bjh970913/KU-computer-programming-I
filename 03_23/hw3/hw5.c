#include <stdio.h>

int main(int argc, char const *argv[])
{
    double pi = 0.0;
    double num = 4.0;
    double denom = 1.0;
    long int loop;
    long int accuracy;

    accuracy  = 900000;

    printf("accuracy set at %ld\n", accuracy);
    printf("Term\t\tpi\n");

    for (loop = 1; loop <= accuracy; loop++)
    {
        pi += ((loop%2==0)?-1:1) * (num / denom);
        // printf("%f|%f|%f\n", num, denom, ((loop%2==0)?-1:1) * (num / denom));
        denom += 2.0;

        if (loop%50000 == 0)
        {
            printf("%ld\t\t%f\n", loop, pi);
        }
    }
    return 0;
}