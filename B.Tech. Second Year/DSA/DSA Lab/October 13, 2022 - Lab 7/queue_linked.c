#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->link = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
    printf("Node is Inserted\n\n");
}
int dequeue()
{
    if (front == NULL)
    {
        printf("\nUnderflow\n");
        return -1;
    }
    else
    {
        struct node *temp = front;
        int temp_data = front->data;
        front = front->link;
        free(temp);
        return temp_data;
    }
}
void traverse()
{
    struct node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nEmpty..\n");
    }
    else
    {
        printf("\nQueue..\n");
        temp = front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}
int main()
{
    int choice, val;
    while (choice != 4)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the val to insert: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            printf("Popped element: %d\n", dequeue());
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid..\n");
        }
    }
    return 0;
}