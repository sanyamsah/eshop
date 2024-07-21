#include <stdio.h>
#include <stdlib.h>
struct node
{
    int c, e;
    struct node *link;
};
void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->c);
        printf("Element: %d\n", ptr->e);
        ptr = ptr->link;
    }
}
int main()
{
    struct node *head, *end, *temp, *tail;
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    head = (struct node *)malloc(sizeof(struct node));
    printf("Enter coefficient: ");
    scanf("%d", &head->c);
    printf("Enter power: ");
    scanf("%d", &head->e);
    head->link = NULL;
    temp = head;
    for (int i = 1; i < n; i++)
    {
        end = (struct node *)malloc(sizeof(struct node));
        printf("Enter coefficient: ");
        scanf("%d", &end->c);
        printf("Enter power: ");
        scanf("%d", &end->e);
        end->link = NULL;
        temp->link = end;
        temp = temp->link;
    }
    traverse(head);
}