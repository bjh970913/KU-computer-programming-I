#include <stdio.h>

int main() {
   int in, sum=0;

   printf("Enter an integer: ");
   scanf("%d", &in);

   while(in>0)
   {
      sum += in & 1;
      in = in >> 1;
   }
   printf("The total number of 1s in the bit representation is ");
   if(sum % 2 == 0)
   {
      printf("even\n");
   }
   else
   {
      printf("odd\n");
   }
}