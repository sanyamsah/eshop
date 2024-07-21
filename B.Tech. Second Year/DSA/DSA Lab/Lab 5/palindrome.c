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
struct node *reverse(struct node *mid)
{
    struct node *cur, *last, *temp;
    cur = mid;
    last = NULL;
    while (cur != NULL)
    {
        temp = cur->link;
        cur->link = last;
        last = cur;
        // temp->link = cur;
        cur = temp;
    }
    return last;
}
void palindrome(struct node *head, struct node *prev, int n)
{
    int count = 0;
    struct node *temp1 = head, *temp2 = prev;
    for (int i = 0; i < (n / 2); i++)
    {
        if (temp1->data != temp2->data)
        {
            printf("Not a Palindrome..\n");
            break;
            return;
        }
        temp1 = temp1->link;
        temp2 = temp2->link;
    }
    printf("Palindrome..\n");
}
// struct node *reverse(struct node *head)
// {
//     struct node *cur, *prev, *temp;
//     cur = head;
//     prev = NULL;
//     while (cur != NULL)
//     {
//         temp = cur->link;
//         cur->link = prev;
//         prev = cur;
//         // temp->link = cur;
//         cur = temp;
//     }
//     return prev;
// }

int main()
{
    struct node *head, *end, *temp, *prev, *mid;
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
    for (int i = 0; i < (n / 2); i++)
    {
        mid = mid->link;
    }
    prev = reverse(mid);
    palindrome(head, prev, n);
    // traverse(head);
    return 0;
}