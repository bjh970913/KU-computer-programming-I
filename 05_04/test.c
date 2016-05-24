#include <stdio.h>

// int compare(int a, int b)
// {
//     double aa, bb;
//     aa = a;
//     bb = b;
    
//     while(aa>10)
//     {
//         aa /= 10.0;
//     }
//     while(bb>10)
//     {
//         bb /= 10.0;
//     }

//     while((int)aa == (int)bb)
//     {
//         aa *= 10;
//         bb *= 10;
//     }

//     if((int)aa < (int)bb)
//         return 1;
//     else
//         return 0;
// }

// void print_max(int a[], int nelem){
//     int i, j, tmp;

//     for(i=0;i<nelem;i++)
//     {
//         for(j=0;j<nelem-i-1;j++)
//         {
//             if(compare(a[j] , a[j+1]))
//             {
//                 tmp = a[j];
//                 a[j] = a[j+1];
//                 a[j+1] = tmp;
//             }
//         }
//     }

//     for(i=0;i<nelem;i++)
//     {
//         printf("%d", a[i]);
//     }
//     printf("\n");
// }

// int is_leap_yeay(int year){
//     int ret = 0;

//     if(year%4 == 0)
//     {
//         ret = 1;
//         if(year%100 ==0)
//         {
//             ret = 0;
//             if(year%400 == 0)
//             {
//                 ret = 1;
//             }
//         }
//     }
//     return ret;
// }

// int is_prime(int n){
//     int i;

//     for(i=2;i<n/2;i++)
//     {
//         if(n%i ==0)
//             return 0;
//     }
//     return 1;
// }

// int is_circular_prime(int n){
//     int dd = 0, tmp, i, j;

//     tmp = n;
//     while(tmp>0)
//     {
//         dd++;
//         tmp /= 10;
//     }

//     for(i=0;i<dd;i++)
//     {
//         tmp = n % 10;
//         n /= 10;
//         for(j=0;j<dd-1;j++)
//         {
//             tmp*=10;
//         }
//         n+=tmp;

//         if(!is_prime(n))
//         {
//             return 0;
//         }
//     }
//     return 1;
// }

void make_100(){
    int devide[9] = {1,}, i, j;

    for(i=2;i<=9;i++)
    {
        int sum=9;
        flush_devide();
        for(j=0;j<i;j++)
        {
            devide[j]
        }
    }
}

int main(int argc, char const *argv[])
{
    // int c[] = {50, 54, 1, 9};

    // print_max(c, 4);

    // printf("%d\n", is_prime(7));
    printf("%d\n", is_circular_prime(9711));

    return 0;
}