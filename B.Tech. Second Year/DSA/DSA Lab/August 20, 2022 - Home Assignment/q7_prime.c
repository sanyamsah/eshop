#include <stdio.h>
int main()
{
    int n, flag = 0;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    if (n == 1 || n == 0)
    {
        printf("Neither Prime, Nor Composite\n");
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("Composite.\n");
    }
    else
    {
        printf("Prime.\n");
    }
    return 0;
}