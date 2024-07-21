#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, sum = 0;
    int r;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("\nMemory allocation failed..\n");
        exit(0);
    }
    printf("Enter the numbers..\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    printf("Sum = %d\n", sum);
    printf("Enter the number of additional array elements: ");
    scanf("%d", &r);
    arr = (int *)realloc(arr, (r + n) * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed..\n");
        exit(0);
    }
    printf("Enter %d more numbers: ", r);
    for (i = n; i < (n + r); i++)
    {
        scanf("%d", arr + i);
    }
    for (i = n; i < (n + r); i++)
    {
        sum += *(arr + i);
    }
    printf("Sum = %d\n", sum);
    free(arr);
    return 0;
}