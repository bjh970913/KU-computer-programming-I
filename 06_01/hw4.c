#include <stdio.h>

struct STUDENT{
    char name[40];
    int stdnum;
    int year;
    char major[10];
}typedef sutdent;

int main(int argc, char const *argv[])
{
    sutdent stds[5] = {0,};
    FILE *fp = fopen("./hw4_/student_file.txt", "wb");
    int i, num;

    fprintf(fp, "Name\tstdnum\t\tYear\tMajor\n");
    for(i=0; i<5; i++)
    {
        printf("Name student_number Year Major: ");
        scanf("%s", stds[i].name);
        scanf("%d", &(stds[i].stdnum));
        scanf("%d", &(stds[i].year));
        scanf("%s", stds[i].major);

        fprintf(fp, "%4s\t", stds[i].name);
        fprintf(fp, "%d\t", stds[i].stdnum);
        fprintf(fp, "%d\t\t", stds[i].year);
        fprintf(fp, "%s\n", stds[i].major);
    }

    printf("Insert the student number to find: ");
    scanf("%d", &num);

    for(i=0; i<5; i++)
    {
        if(stds[i].stdnum == num)
        {
            printf("The major of student with ID %d is %s\n", stds[i].stdnum, stds[i].major);
            break;
        }
    }
    return 0;
}