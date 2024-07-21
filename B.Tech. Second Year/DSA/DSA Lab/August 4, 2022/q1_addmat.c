#include <stdio.h>
void sum(int r, int c, int mat1[r][c], int mat2[r][c], int res[r][c])
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            *(*(res + i) + j) = (*(*(mat1 + i) + j)) + (*(*(mat2 + i) + j));
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", *(*(res + i) + j));
        }
        printf("\n");
    }
}
int main()
{
    int r, c, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    int mat1[r][c], mat2[r][c], res[r][c];
    printf("Enter matrix 1..\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", *(mat1 + i) + j);
        }
    }
    printf("Enter matrix 2..\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", *(mat2 + i) + j);
        }
    }
    printf("Sum..\n");
    sum(r, c, mat1, mat2, res);
    return 0;
}