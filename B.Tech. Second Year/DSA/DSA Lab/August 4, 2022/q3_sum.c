#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < n; i++)
    {
        sum += *(arr + i);
    }
    printf("Sum = %d", sum);
    return 0;
}