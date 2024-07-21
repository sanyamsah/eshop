#include <stdio.h>
int main()
{
    int n;
    printf("Enter the day of the week in number: ");
    scanf("%d", &n);
    if (n > 7 || n < 1)
    {
        printf("Enter valid number..\n");
    }
    else
    {
        switch (n)
        {
        case 1:
            printf("Sunday\n");
            break;
        case 2:
            printf("Monday\n");
            break;
        case 3:
            printf("Tuesday\n");
            break;
        case 4:
            printf("Wednesday\n");
            break;
        case 5:
            printf("Thursday\n");
            break;
        case 6:
            printf("Friday\n");
            break;
        case 7:
            printf("Saturday\n");
            break;
        }
    }
    return 0;
}