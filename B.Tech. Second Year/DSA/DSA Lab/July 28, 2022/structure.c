#include <stdio.h>

struct num
{
    int a, b;
};

int main()
{
    struct num num1, num2;
    printf("\nFor structure 1..\n");
    printf("Enter a number: ");
    scanf("%d", &num1.a);
    printf("Enter another number: ");
    scanf("%d", &num1.b);
    printf("For structure 2..\n");
    printf("Enter a number: ");
    scanf("%d", &num2.a);
    printf("Enter another number: ");
    scanf("%d", &num2.b);
    if (num1.a + num1.b == num2.a + num2.b)
    {
        printf("\nTheir sums are equal.\n");
    }
    else
    {
        printf("\nTheir sums are not equal.\n");
    }
    return 0;
}