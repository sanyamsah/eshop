#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *a;
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            if (*(a + i) > *(a + j))
            {
                temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
    printf("Which largest element you wanna know?: ");
    scanf("%d", &i);
    printf("Which smallest element you wanna know?: ");
    scanf("%d", &j);
    printf("\nThe %dth smallest element is: %d", i, a[n - i]);
    printf("\nThe %dth largest element is: %d", j, a[j - 1]);
    return 0;
}