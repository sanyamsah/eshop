#include <stdio.h>
int min(int a[], int size, int p)
{
    int j, temp;
    for (j = p; j < size; j++)
    {
        int m = a[p];
        if (a[j] < m)
        {
            m = a[j];
            temp = j;
        }
    }
    return temp;
}
int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter array elements..\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < size; i++)
    {
        int m = min(a, size, i + 1);
        if (a[i] > m)
        {
            int temp = a[i];
            a[i] = a[m];
            a[m] = temp;
        }
    }
    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    return 0;
}