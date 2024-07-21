#include <stdio.h>
int main()
{
    int n, i, j, flag;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n], nge[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n - 1; j++)
        {
            if (a[i] < a[j + 1])
            {
                nge[i] = a[j + 1];
                flag = 1;
                break;
            }
        }
        if (flag != 1)
        {
            nge[i] = -1;
        }
        flag = 0;
    }
    printf("Input Array..     NGE..\n");
    for (i = 0; i < n; i++)
    {
        printf("%d                  %d\n", a[i], nge[i]);
    }
    return 0;
}
