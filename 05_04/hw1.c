#include <stdio.h>
#include <string.h>

int main() {
   char str[1000];
   int i1, i2, cnt[100] = { 0, };
   char temp[20][10];
   printf("Enter three lines of text:\n");
   fgets(str, sizeof(str), stdin);
   fgets(str + strlen(str), sizeof(str), stdin);
   fgets(str + strlen(str), sizeof(str), stdin);
   char *context = NULL;
   char *token = strtok(str, " .\n");

   printf("\n");
   for (i1 = 0; token != NULL; i1++) {
      strcpy(temp[i1], token);
      cnt[i1]++;
      token = strtok(NULL, " .\n");
      for (i2 = 0; i2 < i1; i2++) {
         if (strcmp(temp[i1], temp[i2]) == 0) {
            cnt[i2]++;
            cnt[i1]--;
         }
      }
   }

   for (i1 = 0; i1 < 100; i1++) {
      if (cnt[i1] == 1) printf("\"%s\" appeared %d time\n", temp[i1], cnt[i1]);
      else if (cnt[i1] > 1) printf("\"%s\" appeared %d times\n", temp[i1], cnt[i1]);
   }
}