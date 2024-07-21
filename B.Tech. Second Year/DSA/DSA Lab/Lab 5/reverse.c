#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->link;
    }
}
struct node *reverse(struct node *head)
{
    struct node *cur, *prev, *temp;
    cur = head;
    prev = NULL;
    while (cur != NULL)
    {
        temp = cur->link;
        cur->link = prev;
        prev = cur;
        // temp->link = cur;
        cur = temp;
    }
    return prev;
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
    head = reverse(head);
    traverse(head);
    return 0;
}