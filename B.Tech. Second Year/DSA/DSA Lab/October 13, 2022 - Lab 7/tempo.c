#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int size)
{
    struct node *temp;
    temp = (struct node *)malloc(size * sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &front->data);
    temp = front;
    rear = temp;
    for (int i = 1; i < size; i++)
    {
        printf("Enter data: ");
        scanf("%d", &rear->data);
        rear->next = NULL;
        temp->next = rear;
        temp = temp->next;
    }
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
        front = front->next;
        free(temp);
        return temp_data;
    }
}
void display()
{
    struct node *temp;
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nQueue is Empty..\n");
    }
    else
    {
        printf("The queue is..\n");
        temp = front;
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n\n");
    }
}

int main()
{
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    enqueue(size);
    display();
    return 0;
}
