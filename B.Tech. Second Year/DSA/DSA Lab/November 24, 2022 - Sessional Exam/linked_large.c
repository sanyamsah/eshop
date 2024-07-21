#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int largest(struct node *head)
{
    struct node *temp;
    temp = head;
    int large = head->data;
    while (temp != NULL)
    {
        if (temp->data > large)
        {
            large = temp->data;
        }
        temp = temp->next;
    }
    return large;
}
int main()
{
    struct node *head, *new, *temp;
    int n = 5;
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter data 1: ");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &new->data);
        new->next = NULL;
        temp->next = new;
        temp = temp->next;
    }
    largest(head);
    int large = largest(head);
    printf("Largest element: %d\n", large);
    return 0;
}