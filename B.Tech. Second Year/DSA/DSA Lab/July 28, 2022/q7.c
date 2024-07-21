#include <stdio.h>
struct total
{
    int a, b, c, d, e;
};
int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct total sub[n], tot;
    for (int i = 0; i < n; i++)
    {
        printf("\nFor student %d..\n", i + 1);
        printf("Enter marks in DSA: ");
        scanf("%d", &sub[i].a);
        printf("Enter marks in OOP: ");
        scanf("%d", &sub[i].b);
        printf("Enter marks in DE: ");
        scanf("%d", &sub[i].c);
        printf("Enter marks in PS: ");
        scanf("%d", &sub[i].d);
        printf("Enter marks in DMS: ");
        scanf("%d", &sub[i].e);
    }
    tot.a = 0, tot.b = 0, tot.c = 0, tot.d = 0, tot.e = 0;
    for (int i = 0; i < n; i++)
    {
        tot.a += sub[i].a;
        tot.b += sub[i].b;
        tot.c += sub[i].c;
        tot.d += sub[i].d;
        tot.e += sub[i].e;
    }
    printf("\nSubject-wise total marks..");
    printf("\nTotal marks in DSA = %d", tot.a);
    printf("\nTotal marks in OOP = %d", tot.b);
    printf("\nTotal marks in DE = %d", tot.c);
    printf("\nTotal marks in PS = %d", tot.d);
    printf("\nTotal marks in DMS = %d", tot.e);
    return 0;
}