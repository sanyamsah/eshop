#include <stdio.h>
#include <string.h>
struct student
{
    int roll;
    float cgpa;
};
int main()
{
    struct student s1, s2, s3;
    printf("\nFor student 1..\n");
    printf("Enter roll number: ");
    scanf("%d", &s1.roll);
    printf("Enter CGPA: ");
    scanf("%f", &s1.cgpa);
    printf("\nFor student 2..\n");
    printf("Enter roll number: ");
    scanf("%d", &s2.roll);
    printf("Enter CGPA: ");
    scanf("%f", &s2.cgpa);
    s3 = s1;
    if (s2.roll == s3.roll && s2.cgpa == s3.cgpa)
    {
        printf("\nSame");
    }
    else
    {
        printf("\nDifferent");
    }
    return 0;
}