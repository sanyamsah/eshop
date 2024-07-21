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
void interchange(struct node *head, int num)
{
    struct node *temp, *ptr1, *ptr2;
    temp = head;
    int i = 1;
    while (ptr2 != NULL)
    {
        ptr1 = temp->link;
        ptr2 = ptr1->link;
        temp = temp->link;
        if (i == num)
        {
            int a = ptr1->data;
            ptr1->data = ptr2->data;
            ptr2->data = a;
            break;
        }
        i++;
    }
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
    int num;
    printf("Which node to interchange with the next one?: ");
    scanf("%d", &num);
    interchange(head, num - 1);
    return 0;
}