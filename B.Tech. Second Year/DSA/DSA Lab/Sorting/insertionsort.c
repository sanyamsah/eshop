#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void insertionsort(int arr[], int n)
{
    int j;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i];
        // int j = i - 1;
        // while (j >= 0 && arr[j] > temp)
        // {
        //     arr[j + 1] = arr[j];
        //     j--;
        // }
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            min = arr[j];
        }
        if (arr[min] > arr[i])
        {
            swap(&arr[min], &arr[i]);
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    selectionsort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}