#include <stdio.h>
#define max(x, y) x > y ? x : y
int main()
{
    int a, b;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);
    printf("%d is greater.\n", max(a, b));
    return 0;
}
