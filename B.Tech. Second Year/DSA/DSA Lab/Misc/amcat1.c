#include <stdio.h>
int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[size]);
    }
    int sum = 0;
    int j = 0;
    while (j < size)
    {
        sum = sum + arr[j];
        j = j + 2;
    }
    printf("%d", sum);
    return 0;
}