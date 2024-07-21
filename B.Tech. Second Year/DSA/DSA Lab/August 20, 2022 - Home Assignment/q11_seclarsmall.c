#include <stdio.h>
int main()
{
    int n, temp;
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Second largest element: %d\n", arr[1]);
    printf("Second smallest element: %d\n", arr[n - 2]);
    return 0;
}