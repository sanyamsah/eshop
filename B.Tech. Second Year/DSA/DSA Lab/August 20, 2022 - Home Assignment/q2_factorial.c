#include <stdio.h>
int factorial(int n)
{
    int fact = 1;
    for (int i = n; i >= 1; i--)
    {
        fact *= i;
    }
    return fact;
}
int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("%d! = %d\n", a, factorial(a));
    return 0;
}