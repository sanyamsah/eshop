#include <stdio.h>
int main()
{
    int n, i, j, p = 1;
    printf("Enter the number of rows/columns: ");
    scanf("%d", &n);
    int mat[n][n], a[n];
    printf("Enter the %dx%d matrix..\n", n, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("The matrix is..\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("The non-zero elements are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                printf("%d ", mat[i][j]);
            }
        }
    }
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < j)
            {
                sum += mat[i][j];
            }
        }
    }
    printf("\nThe sum of the elements above the leading diagonal = %d", sum);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {

            if (i == j)
            {
                a[i] = mat[i][j];
            }
        }
    }
    printf("\nThe elements of the leading diagonals are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nThe elements below the minor diagonal are: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i + j >= n)
            {
                printf("%d ", mat[i][j]);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                p *= mat[i][j];
            }
        }
    }
    printf("\nThe product of the elements of the leading diagonal = %d", p);
    return 0;
}