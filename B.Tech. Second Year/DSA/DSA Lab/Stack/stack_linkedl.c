#include <stdio.h>
// #include <stdbool.h>
#include <stdlib.h>
int size = 0;
struct node
{
    int data;
    struct node *next;
} *top = NULL;
void push()
{
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    if (top == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = top;
    }
    new = top;
}
void display()
{
    if (top == NULL)
        printf("\nStack is Empty!!!\n");
    else
    {
        struct node *temp = top;
        while (temp->next != NULL)
        {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL", temp->data);
    }
}
// void peek()
// {
//     printf("%d ", top->data);
// }
int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    push();
    push();
    // peek();
    // peek();
}