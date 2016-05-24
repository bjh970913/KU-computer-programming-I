#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[80];
    int stdnum;
};

int main(int argc, char const *argv[])
{
    int i, j;
    char buff[1000];
    struct student *students[5], *tmp;

    for(i=0; i<5; i++)
    {
        printf("(%d) ", i);
        printf("Enter student name / student number: ");
        gets(buff);

        tmp = (struct student *)malloc(sizeof(struct student));

        strcpy(tmp->name, strtok(buff, "/"));
        tmp->stdnum = atoi(strtok(NULL, " /"));

        students[i] = tmp;
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5-i-1;j++)
        {
            if(students[j]->stdnum > students[j+1]->stdnum)
            {
                tmp = students[j];
                students[j] = students[j+1];
                students[j+1] = tmp;
            }
        }
    }

    printf("\n");
    printf("ID\t\t\t\tName\n");
    for(i=0; i<5; i++)
    {
        printf("%d\t\t%s\n", students[i]->stdnum, students[i]->name);
    }
    return 0;
}