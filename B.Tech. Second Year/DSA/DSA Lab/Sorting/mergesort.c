#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int arr[], int l, int mid, int u)
{
    int brr[u];
    int i = l;
    int j = mid + 1;
    int k = l;
    while (i <= mid && j <= u)
    {
        if (arr[i] < arr[j])
        {
            brr[k] = arr[i];
            i++;
        }
        else
        {
            brr[k] = arr[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= u)
        {
            brr[k] = arr[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            brr[k] = arr[i];
            k++;
            i++;
        }
    }
    for (i = l; i <u; k++)
    {
        arr[i] = brr[i];
    }
}
void mergesort(int arr[], int l, int u)
{
    if (l < u)
    {
        int mid = (l + u) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, u);
        merge(arr, l, mid, u);
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
    mergesort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}