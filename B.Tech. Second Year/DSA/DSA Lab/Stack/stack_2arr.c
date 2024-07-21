#include <stdio.h>
int size = 10;
int topa = 0, topb = 9;
void pusha(int stack[])
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    if (topa - 1 == topb || topa == size - 1 || topb == -1)
    {
        printf("Overflow..\n");
    }
    else
    {
        stack[topa] = data;
        topa++;
    }
}
void pushb(int stack[])
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
    if (topa - 1 == topb || topa == size - 1 || topb == -1)
    {
        printf("Overflow..\n");
    }
    else
    {
        stack[topb] = data;
        topb--;
    }
}
// void peeka(int stack[])
// {
//     printf("%d ", stack[topa]);
// }
int main()
{
    int stack[size];
    for (int i = 0; i < 5; i++)
    {
        pusha(stack);
    }
    for (int i = 5; i < size; i++)
    {
        pushb(stack);
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", stack[i]);
    }
    // peeka(stack);
}