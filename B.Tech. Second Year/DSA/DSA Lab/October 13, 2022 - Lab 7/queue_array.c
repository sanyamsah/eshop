#include <stdio.h>
#include <stdlib.h>
int front, rear, size;
int queue[20];
front = -1;
rear = -1;
void enqueue(int size)
{
    if (front == -1)
    {
        front = 0;
    }
    if (rear == size - 1)
    {
        printf("Overflow..\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            printf("Enter data: ");
            rear++;
            scanf("%d", &queue[rear]);
        }
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow..\n");
        return;
    }
    else
    {
        printf("\nDeleted element: %d\n", queue[front]);
        front++;
    }
}
void display()
{
    if (front == -1)
    {
        printf("Empty..\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("- - - - - - - - MENU - - - - - - - -\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter size: ");
            scanf("%d", &size);
            enqueue(size);
        case 2:
            dequeue();
        case 3:
            display();
        default:
            printf("Exiting..");
            exit(0);
        }
    } while (choice != 4);
    return 0;
}