#include <stdio.h>
#include<string.h>
struct student
{
    char name[20];
    int roll;
    float cgpa;
};
int main()
{
    struct student stu[10];
    for (int i = 0; i < 10; i++)
    {
        printf("\nFor student %d..\n", i + 1);
        printf("Enter name: ");
        // gets(stu[i].name);
        scanf("%s", stu[i].name);
        // fgets(stu[i].name, 30, stdin);
        printf("Enter roll number: ");
        scanf("%d", &stu[i].roll);
        printf("Enter CGPA: ");
        scanf("%f", &stu[i].cgpa);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("\n");
        printf("\nName: %s", stu[i].name);
        printf("\nRoll number: %d", stu[i].roll);
        printf("\nCGPA: %.2f", stu[i].cgpa);
    }
    return 0;
}