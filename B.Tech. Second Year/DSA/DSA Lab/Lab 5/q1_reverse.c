#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->link;
    }
}
void reverse(struct node *head)
{
    struct node *temp, *prev = NULL, *next;
    temp = head;
    while (temp != NULL)
    {
        next = temp->link;
        temp->link = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    traverse(head);
}

int main()
{
    struct node *head, *end, *temp;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter data 1: ");
    scanf("%d", &head->data);
    head->link = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        end = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &end->data);
        end->link = NULL;
        temp->link = end;
        temp = temp->link;
    }
    // traverse(head);
    reverse(head);
}