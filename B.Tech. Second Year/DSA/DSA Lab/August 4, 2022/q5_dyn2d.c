#include <stdio.h>
#include <stdlib.h>
int main()
{
    int r, c, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);
    int **mat = (int **)malloc(r * c * sizeof(int));
    printf("Enter the matrix..\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
    return 0;
}