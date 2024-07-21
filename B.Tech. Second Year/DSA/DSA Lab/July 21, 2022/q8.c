#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, x, y, dis;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((x == a[i] && y == a[j] || y == a[i] && x == a[j]) && dis > abs(i - j))
            {
                dis = abs(i - j);
            }
        }
    }
    if (dis > n)
    {
        printf("-1");
    }
    else
    {
        printf("The minimum distance between %d & %d is %d.\n", x, y, dis);
    }
}