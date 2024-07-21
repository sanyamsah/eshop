#include <stdio.h>
int main()
{
    int n, i, j, k, temp;
    printf("Enter the number of elements in the array: ");
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
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nEnter which smallest value you wanna search: ");
    scanf("%d", &k);
    if (k == 1)
    {
        printf("The smallest value is %d", a[k - 1]);
    }
    else if (k == 2)
    {
        printf("The %dnd smallest value is %d", k, a[k - 1]);
    }
    else if (k == 3)
    {
        printf("The %drd smallest value is %d", k, a[k - 1]);
    }
    else
    {
        printf("The %dth smallest value is %d", k, a[k - 1]);
    }
    return 0;
}