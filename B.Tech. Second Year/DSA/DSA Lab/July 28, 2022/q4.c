#include <stdio.h>
#include <math.h>
struct points
{
    int x, y;
};
int main()
{
    struct points p1, p2;
    float add;
    printf("\nFor point 1..\n");
    printf("Enter the abscissa: ");
    scanf("%d", &p1.x);
    printf("Enter the ordinate: ");
    scanf("%d", &p1.y);
    printf("\nFor point 2..\n");
    printf("Enter the abscissa: ");
    scanf("%d", &p2.x);
    printf("Enter the ordinate: ");
    scanf("%d", &p2.y);
    add = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    printf("\nThe distance between (%d,%d) & (%d,%d) is %.2f.", p1.x, p1.y, p2.x, p2.y, add);
    return 0;
}