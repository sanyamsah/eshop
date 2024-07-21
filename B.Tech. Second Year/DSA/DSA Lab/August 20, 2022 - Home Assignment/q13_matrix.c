#include <stdio.h>

int nonzero(int n, int mat[][n])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}

int sumabdia(int n, int mat[][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}

void belowmin(int n, int mat[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) >= n)
            {
                printf("%d ", mat[i][j]);
            }
        }
    }
}

int proddia(int n, int mat[][n])
{
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                prod *= mat[i][j];
            }
        }
    }
    return prod;
}

int main()
{
    int n, i, j;
    printf("Enter the number of rows/columns: ");
    scanf("%d", &n);
    int mat[n][n];
    printf("Enter the elements..\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("Number of non-zero elements: %d\n", nonzero(n, mat));
    printf("Sum of the elements above the leading diagonal: %d\n", sumabdia(n, mat));
    printf("Elements below minor diagonal: ");belowmin(n, mat);
    printf("\nProduct of the diagonal elements: %d\n", proddia(n, mat));
    return 0;
}