#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create()
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter data (Enter -1 for no further node): ");
    scanf("%d", &x);
    new->data = x;
    if (x == -1)
    {
        return 0;
    }
    printf("For left child of %d..\n", x);
    new->left = create();
    printf("For right child of %d..\n", x);
    new->right = create();
    return new;
}
void preorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root == 0)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    root = create();
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    return 0;
}