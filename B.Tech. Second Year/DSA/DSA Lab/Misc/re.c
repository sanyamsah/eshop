#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, sum = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr;
    arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("Space not available.");
        exit(0);
    }
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("Sum of the elements: %d\n", sum);
    return 0;
}