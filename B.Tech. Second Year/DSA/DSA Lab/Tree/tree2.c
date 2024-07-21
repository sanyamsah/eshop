//postorder&pre
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
typedef struct stack
{
    int size;
    int top;
    node **sarr;
} stack;
void createStack(stack *s, int n)
{
    s->size = n;
    s->top = -1;
    s->sarr = (node *)malloc(sizeof(node) * n);
}
void push(stack s, node p)
{
    if (s->top == s->size - 1)
        printf("Stack is full\n");
    else
    {
        // s->top++;
        s->sarr[++s->top] = p;
        // printf("\npushed\n");
    }
}
node *pop(stack *s)
{
    node *tmp = NULL;
    if (s->top == -1)
        printf("Stack is underflowed\n");
    else
    {
        tmp = s->sarr[s->top--];
        // s->top--;
        // printf("\npopped\n");
    }
    return tmp;
}
int isEmpty(stack s)
{
    return s.top == -1;
}
int isFull(stack s)
{
    return s.top == s.size - 1;
}
node *createNode(int a)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = a;
    new->left = NULL;
    new->right = NULL;
    return new;
}
void createTree(node **root, int n)
{
    int r;
    printf("Give root node data: ");
    scanf("%d", &r);
    *root = createNode(r);
    stack s;
    createStack(&s, n);
    push(&s, *root);
    while (!isEmpty(s))
    {
        node *tmp = pop(&s);
        int l, r;
        printf("Give left child of %d: ", tmp->data);
        scanf("%d", &l);
        if (!(l == -1))
        {
            tmp->left = createNode(l);
            push(&s, tmp->left);
        }
        printf("Give right child of %d: ", tmp->data);
        scanf("%d", &r);
        if (!(r == -1))
        {
            tmp->right = createNode(r);
            push(&s, tmp->right);
        }
    }
}
void preorderR(node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorderR(p->left);
        preorderR(p->right);
    }
}
void preorderI(node *tmp)
{
    stack s;
    createStack(&s, 10);
    // printf("%d ",p->data);
    // node *tmp=p;
    while (!isEmpty(s) || tmp)
    {
        if (tmp)
        {
            printf("%d ", tmp->data);
            push(&s, tmp);
            tmp = tmp->left;
        }
        else
        {
            tmp = pop(&s);
            tmp = tmp->right;
        }
    }
    printf("\n");
}

int main(void)
{
    node *root;
    int n;
    printf("Give no of nodes: ");
    scanf("%d", &n);
    createTree(&root, n);
    preorderI(root);
    preorderR(root);
    puts("\n");
}