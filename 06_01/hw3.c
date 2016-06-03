#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp1, *fp2;
    char file1[1000], file2[1000], *str_p;
    char buff[10000] = {0,};

    printf("Enter the name of file to read: ");
    scanf("%s", file1);
    printf("Enter the name of file to write: ");
    scanf("%s", file2);
    
    fp1 = fopen(file1, "r");
    fread(buff, 1000, 1, fp1);
    fclose(fp1);

    fp2 = fopen(file2, "w");
    
    str_p = strtok(buff, "\r\n");
    while(str_p)
    {
        fprintf(fp2, "%s\n", str_p);
        str_p = strtok(NULL, "\r\n");
    }

    fclose(fp2);

    printf("Copy text complete!\n");

    return 0;
}