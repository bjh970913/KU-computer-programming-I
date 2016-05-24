#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    int tmp;
    int arr[2][3];

    fp = fopen("./hw1_/input1.txt", "r");
    fscanf(fp, "%d%d", &tmp, &tmp);

    printf("input1 matrix:\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            fscanf(fp, "%d", &tmp);
            arr[i][j] = tmp;
            printf("%d  ", tmp);
        }
        printf("\n");
    }
    printf("\n");

    fp = fopen("./hw1_/input2.txt", "r");
    fscanf(fp, "%d%d", &tmp, &tmp);
    printf("input1 matrix:\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            fscanf(fp, "%d", &tmp);
            arr[i][j] += tmp;
            printf("%d  ", tmp);
        }
        printf("\n");
    }
    printf("\n");

    fp = fopen("./hw1_/result.txt", "w");
    printf("result matrix:\n");
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<3; j++)
        {
            fprintf(fp, "%d ", arr[i][j]);
            printf("%d  ", arr[i][j]);
        }
        fprintf(fp, "\n");
        printf("\n");
    }

    return 0;
}