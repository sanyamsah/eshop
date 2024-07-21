#include <stdio.h>

void sortrow(int m, int n, int mat[][n])
{
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (mat[i][j] < mat[i][k])
                {
                    int temp = mat[i][j];
                    mat[i][j] = mat[i][k];
                    mat[i][k] = temp;
                }
            }
        }
    }
}

void sortcol(int m, int n, int mat[][n])
{
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (mat[j][i] > mat[k][i])
                {
                    int temp = mat[j][i];
                    mat[j][i] = mat[k][i];
                    mat[k][i] = temp;
                }
            }
        }
    }
}
int main()
{
    int m, n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);
    int mat[m][n];
    printf("Enter the elements..\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Rows sorted in ascending order..\n");
    sortrow(m, n, mat);
    for (int i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Columns sorted in descending order..\n");
    sortcol(m, n, mat);
    for (int i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}