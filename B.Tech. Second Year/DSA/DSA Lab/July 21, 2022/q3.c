#include <stdio.h>
int main()
{
    int n, i, x;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Given array..\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nEnter the element you wanna search: ");
    scanf("%d", &x);
    for (i = 0; i < n; i++)
    {
        if (x == a[i])
        {
            printf("The given element is present in index %d.\n", i);
        }
    }
    return 0;
}