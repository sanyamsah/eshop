#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};

struct Student
{
    char name[20];
    struct date dob;
};

int main()
{
    struct Student s[50];
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Enter Name of student %d: ", i + 1);
        gets(s[i].name);

        printf("Enter your Date of Birth (dd/mm/yy):");
        scanf("%d%d%d", &s[i].dob.day, &s[i].dob.month, &s[i].dob.year);
    }
    printf("\n");

    printf("-----Details of the student-----\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Details of Student %d\n", i + 1);
        printf("Name: %s\n", s[i].name);
        printf("Date of Birth (dd/mm/yy): %d/%d/%d\n", s[i].dob.day, s[i].dob.month, s[i].dob.year);
        printf("\n");
    }
    return 0;
}