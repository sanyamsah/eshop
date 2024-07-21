#include <stdio.h>
#include <math.h>
int main()
{
    int n, p = 0, rem, sum = 0;
    printf("Enter a multi-digit number: ");
    scanf("%d", &n);
    int temp1, temp2;
    temp1 = temp2 = n;
    while (temp1 != 0)
    {
        temp1 /= 10;
        p++;
    }
    while (n != 0)
    {
        rem = n % 10;
        sum = sum + pow(rem, p);
        n /= 10;
    }
    if (temp2 == sum)
    {
        printf("Armstrong.\n");
    }
    else
    {
        printf("Not an Armstrong.\n");
    }
    return 0;
}