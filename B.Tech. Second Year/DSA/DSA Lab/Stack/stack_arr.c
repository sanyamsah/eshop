#include <stdio.h>
#include <stdbool.h>
#define size 10
int top = -1;
int arr[5];
void push(int data)
{
    if (top == size - 1)
    {
        printf("Overflow..\n");
    }
    else
    {
        top++;
        arr[top] = data;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("Overflow..\n");
        return 0;
    }
    else
    {
        top--;
        return arr[top];
    }
}
int peek()
{
    if (top == -1)
    {
        printf("Underflow..\n");
        return 0;
    }
    else
        return arr[top];
}
bool isempty()
{
    return top == -1;
}
int main()
{
    int arr[size];
    
}