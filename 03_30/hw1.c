#include <stdio.h>
#include <math.h>

double hypotenuse(double a, double b);

int main(int argc, char const *argv[])
{
    double a,b;

    printf("Enter the sides of the triangle: ");
    scanf("%lf%lf", &a, &b);

    printf("Hypotenuse:\t%.1lf\n", hypotenuse(a, b));
    return 0;
}

double hypotenuse(double a, double b)
{
    return sqrt(a*a+b*b);
}