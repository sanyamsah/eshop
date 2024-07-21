#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
} *head = NULL;
// void create(){
//     struct node *newnode, *current;
//     newnode=(struct node*)malloc(sizeof(struct node));
//     printf("Enter data: ");
//     scanf("%d", &newnode->data);
//     newnode->link=NULL;
//     if(head==NULL){
//         head=newnode;
//     }
//     else{
//         current=head;
//         current=current->link;
//         current->link=newnode;
//     }
// }
int main()
{
    struct node *head = NULL, *current = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    current->data = 20;
    current->link = NULL;
    head->link = current;
    head->link->link = current;
    printf("%d", head->data);
    printf("%d", current->data);
}