#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

void createMatrix(int matrix[ROW][COL]);
void rotateMatrix(int src[ROW][COL], int dest[ROW][COL]);

int main(int argc, char const *argv[])
{
    int a[ROW][COL], b[ROW][COL];
    int i, j;
    srand(time(NULL));
    
    createMatrix(a);
    rotateMatrix(a, b);

    printf("matrix:\n");
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("result:\n");
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            printf("%3d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void createMatrix(int matrix[ROW][COL])
{
    int i, j;

    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            matrix[i][j] = rand()%100+1;
        }
    }
    return;
}

void rotateMatrix(int src[ROW][COL], int dest[ROW][COL])
{
    int i, j, row, col;
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            row = ((i-2) * 0 + (j-2) * 1)+2;
            col = ((i-2) * -1 + (j-2) * 0)+2;
            dest[row][col] = src[i][j];
        }
    }
    return;
}