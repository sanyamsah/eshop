#include <stdio.h>
struct student
{
    char name[30];
    int roll;
    float cgpa;
};
int main()
{
    struct student stu;
    printf("\nEnter Name: ");
    gets(stu.name);
    printf("Enter Roll no.: ");
    scanf("%d", &stu.roll);
    printf("Enter CGPA: ");
    scanf("%f", &stu.cgpa);
    printf("\nName: %s", stu.name);
    printf("\nRoll no.: %d", stu.roll);
    printf("\nCGPA: %.2f", stu.cgpa);
    return 0;
}