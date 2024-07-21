#include <stdio.h>
int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The array elements are..\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nArray in reverse order..\n");
    for (i = n - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }
    return 0;
}