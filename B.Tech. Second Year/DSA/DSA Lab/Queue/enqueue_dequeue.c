#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int val)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Element inserted..\n");
}
int dequeue()
{
    if (front == NULL)
    {
        printf("Underflow..\n");
        return -1;
    }
    else
    {
        int temp = front->data;
        front = front->next;
        return temp;
    }
}
void traversal()
{
    struct node *temp;
    if (front == NULL && rear == NULL)
    {
        printf("Queue empty..\n");
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}
int main()
{
    int n, val;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &val);
        enqueue(val);
    }
    traversal();
    dequeue();
    printf("\n");
    traversal();
    return 0;
}