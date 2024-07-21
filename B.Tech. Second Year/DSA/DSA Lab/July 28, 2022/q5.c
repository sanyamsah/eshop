#include <stdio.h>

struct dist
{
    int f, i;
};

int main()
{
    struct dist dis1, dis2, sum;
    printf("For distance 1..\n");
    printf("Enter distance in feet: ");
    scanf("%d", &dis1.f);
    printf("Enter distance in inch: ");
    scanf("%d", &dis1.i);
    printf("For distance 2..\n");
    printf("Enter distance in feet: ");
    scanf("%d", &dis2.f);
    printf("Enter distance in inch: ");
    scanf("%d", &dis2.i);
    sum.i = dis1.i + dis2.i;
    sum.f = dis1.f + dis2.f + (sum.i / 12);
    sum.i = sum.i % 12;
    printf("%d feet & %d inch + %d feet + %d inch = %d feet & %d inch.", dis1.f, dis1.i, dis2.f, dis2.i, sum.f, sum.i);
    return 0;
}