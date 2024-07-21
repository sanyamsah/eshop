#include <stdio.h>

struct date
{
    int y, m, d;
};

int main()
{
    struct date birth, today, age;
    printf("\nEnter today's date (YYYY MM DD): ");
    scanf("%d%d%d", &today.y, &today.m, &today.d);
    printf("\nEnter your date of birth (YYYY MM DD): ");
    scanf("%d%d%d", &birth.y, &birth.m, &birth.d);

    if (birth.y > today.y)
    {
        printf("Enter valid date..\n");
    }
    else if (birth.y == today.y && birth.m > today.m)
    {
        printf("Enter valid date..\n");
    }
    else
    {
        age.y = today.y - birth.y;
        if (today.m < birth.m)
        {
            age.m = today.m + 12 - birth.m;
            age.y--;
        }
        else if (today.m >= birth.m)
        {
            age.m = today.m - birth.m;
        }
        if (today.d < birth.d)
        {
            age.d = today.d + 30 - birth.d;
            age.m--;
        }
        else if (today.d >= birth.d)
        {
            age.d = today.d - birth.d;
        }
        printf("\nHey! You're %d years, %d months & %d days old!\n\n", age.y, age.m, age.d);
    }
    return 0;
}