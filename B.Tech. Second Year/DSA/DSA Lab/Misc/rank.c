#include <stdio.h>
#include <string.h>
struct student
{
    int roll;
    char name[30];
    int m1, m2, m3;
    double grade;
} s[10], temp;
int main()
{
    int n, i, j;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        // gets(s[i].name);
        printf("Enter the marks in three subjects: ");
        scanf("%d%d%d", &s[i].m1, &s[i].m2, &s[i].m3);
        s[i].grade = ((((s[i].m1 / 10) + 1) * 3) + (((s[i].m2 / 10) + 1) * 3) + (((s[i].m3 / 10) + 1) * 3)) / 9.0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (s[i].grade > s[j].grade)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    int r;
    printf("Enter student's roll number: ");
    scanf("%d", &r);
    for (int i = 0; i < n; i++)
    {
        if (r == s[i].roll)
        {
            printf("Rank = %d\n", i + 1);
        }
    }
    return 0;
}