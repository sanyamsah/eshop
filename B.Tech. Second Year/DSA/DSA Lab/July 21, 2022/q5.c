#include <stdio.h>
int main()
{
    int n, i, j, temp, a, b;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nThe array elements are..\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nSorted array..\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nEnter lower range: ");
    scanf("%d", &a);
    printf("Enter higher range: ");
    scanf("%d", &b);
    printf("Elements between %d & %d: ", a, b);
    for (i = 0; i < n; i++)
    {
        if (arr[i] > a && arr[i] < b)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}