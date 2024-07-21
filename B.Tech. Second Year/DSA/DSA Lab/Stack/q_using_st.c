#include <stdio.h>
#include <stdbool.h>
int size = 5;
int topa = -1, topb = -1;
void pusha(int stacka[], int data)
{
    if (topa == size - 1)
    {
        printf("Stack A Overflow..\n");
    }
    else
    {
        topa++;
        stacka[topa] = data;
    }
}
void pushb(int stackb[], int data)
{
    if (topb == size - 1)
    {
        printf("Stack B Overflow..\n");
    }
    else
    {
        topb++;
        stackb[topb] = data;
    }
}
int popa(int stacka[])
{
    int res;
    if (topa == -1)
    {
        printf("Stack A Underflow..\n");
    }
    else
    {
        res = stacka[topa];
        topa--;
    }
    return res;
}
int popb(int stackb[])
{
    int res;
    if (topb == -1)
    {
        printf("Stack B Underflow..\n");
    }
    else
    {
        res = stackb[topb];
        topb--;
    }
    return res;
}
int peek(int stackb[])
{
    return stackb[topb];
}
int main()
{
    int stacka[size];
    int stackb[size];
    pusha(stacka, 1);
    pusha(stacka, 2);
    pusha(stacka, 3);
    pusha(stacka, 4);
    pusha(stacka, 5);
    pusha(stacka, 6);

    pushb(stackb, popa(stacka));
    pushb(stackb, popa(stacka));
    pushb(stackb, popa(stacka));
    pushb(stackb, popa(stacka));
    pushb(stackb, popa(stacka));
    pushb(stackb, popa(stacka));
    printf("%d", peek(stackb));
}