#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STUDENT
{
    char name[40];
    int stdnum;
    int kor;
    int math;
    int eng;
    float avg;
}typedef student;

void NT_TextModeRead(FILE *fp, char *buff, int length);

int main(int argc, char const *argv[])
{
    int i, j, tmp, len;
    int stds_rank[5];
    char buff[10000] = {0, };
    FILE *fp1 = fopen("./hw5_/stdlist.txt", "rb");
    FILE *fp2 = fopen("./hw5_/resultlist.txt", "w");
    student stds[5];

    NT_TextModeRead(fp1, (char *)&stds, sizeof(stds));

    printf("Name\t\tID\tavg\t\tKOR\t\tMATH\t\tENG\n");
    for(i=0; i<5; i++)
    {
        stds_rank[i] = i;
        printf("%s\t", stds[i].name);
        printf("%d\t", stds[i].stdnum);
        printf("%f\t", stds[i].avg);
        printf("%d\t\t", stds[i].kor);
        printf("%d\t\t", stds[i].math);
        printf("%d\n", stds[i].eng);
    }

    for(i=1; i<5; i++)
    {
        for(j=0; j<5-i; j++)
        {
            if(stds[stds_rank[j]].avg < stds[stds_rank[j+1]].avg)
            {
                tmp = stds_rank[j];
                stds_rank[j] = stds_rank[j+1];
                stds_rank[j+1] = tmp;
            }
        }
    }

    len = 0;
    len += sprintf(buff+len, "Name\t\tID\tavg\t\tKOR\t\tMATH\t\tENG\n");
    for(i=0; i<5; i++)
    {
        tmp = stds_rank[i];
        len += sprintf(buff+len, "%s\t", stds[tmp].name);
        len += sprintf(buff+len, "%d\t", stds[tmp].stdnum);
        len += sprintf(buff+len, "%f\t", stds[tmp].avg);
        len += sprintf(buff+len, "%d\t\t", stds[tmp].kor);
        len += sprintf(buff+len, "%d\t\t", stds[tmp].math);
        len += sprintf(buff+len, "%d\n", stds[tmp].eng);
    }

    printf("\n%s\n", buff);
    fprintf(fp2, "%s", buff);
    return 0;
}

void NT_TextModeRead(FILE *fp, char *buff, int length)
{
    int idx1, idx2, sz;
    char tmp, *buffer;

    fseek(fp, 0, SEEK_END);
    sz = ftell(fp);
    buffer = (char *)malloc(sz+1);
    rewind(fp);
    
    fread(buffer, sz, 1, fp);
    buffer[sz] = 0;

    idx1 = 0;
    idx2 = 0;
    while(1)
    {
        tmp = buffer[idx1];idx1++;
        if(tmp == 0x0d)
        {
            tmp = buffer[idx1];idx1++;
        }
        buff[idx2] = tmp;
        idx2++;

        if(idx2 == length || idx1 == sz)
        {
            break;
        }
    }
}