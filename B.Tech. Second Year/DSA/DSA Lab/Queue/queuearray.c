#include <stdio.h>
int rear = -1;
void enqueue(int que[], int size)
{
    if (rear == size - 1)
    {
        printf("Queue full..\n");
    }
    else
    {
        rear++;
        printf("Enter data: ");
        scanf("%d", &que[rear]);
    }
}
int dequeue(int que[], int size)
{
    int result;
    if (rear == -1)
    {
        printf("Queue empty..\n");
    }
    else
    {
        result = que[0];
        for (int i = 0; i < rear; i++)
        {
            que[i] = que[i + 1];
        }
        rear--;
    }
    return result;
}
void printarray(int que[])
{
    for (int i = 0; i < rear; i++)
    {
        printf("%d ", que[i]);
    }
}
int main()
{
    int size;
    printf("Enter the size: ");
    scanf("%d", &size);
    int que[size];
    for (int i = 0; i < size; i++)
    {
        enqueue(que, size);
    }
    for (int i = 0; i < size; i++)
    {
        printf("Removed element: %d\n", dequeue(que, size));
    }
    printarray(que);
    return 0;
}