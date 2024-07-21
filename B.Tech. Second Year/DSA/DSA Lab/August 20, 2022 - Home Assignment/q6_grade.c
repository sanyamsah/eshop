#include <stdio.h>
int main()
{
    int marks;
    printf("Enter your marks: ");
    scanf("%d", &marks);
    if (marks > 100 || marks < 0)
    {
        printf("Enter valid marks..\n");
    }
    else
    {
        if (marks >= 90 && marks <= 100)
        {
            printf("Grade: O");
        }
        if (marks >= 80 && marks < 90)
        {
            printf("Grade: E");
        }
        if (marks >= 70 && marks < 80)
        {
            printf("Grade: A");
        }
        if (marks >= 60 && marks < 70)
        {
            printf("Grade: B");
        }
        if (marks >= 50 && marks < 60)
        {
            printf("Grade: C");
        }
        if (marks >= 40 && marks < 50)
        {
            printf("Grade: D");
        }
        if (marks >= 0 && marks < 40)
        {
            printf("FAIL\n");
        }
    }
    return 0;
}