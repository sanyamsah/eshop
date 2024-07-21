#include <stdio.h>
#include <stdlib.h>
int prime(int num)
{
    int flag = 0;
    if (num == 1 || num == 0)
    {
        flag = 2;
    }
    else
    {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}
void insert(int n, int *a)
{
    int pos, num;
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Enter the data: ");
    scanf("%d", &num);
    a = (int *)realloc(a, (n + 1) * sizeof(int));
    n++;
    for (int i = n - 1; i >= pos; i--)
    {
        *(a + i) = *(a + (i - 1));
    }
    a[pos - 1] = num;
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}
void deleteele(int n, int *a)
{
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    for (int i = pos - 1; i < (n - 1); i++)
    {
        *(a + i) = *(a + (i + 1));
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}
void reverse(int n, int *a)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", *(a + i));
    }
}
void search(int n, int *a)
{
    int num;
    printf("Enter the element to search: ");
    scanf("%d", &num);
    for (int i = 0; i < n; i++)
    {
        if (num == a[i])
        {
            printf("Element found at position %d.\n", i + 1);
        }
    }
}
void sort(int n, int *a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) > *(a + j))
            {
                int temp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}
void display(int n, int *a)
{
    printf("Array elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(a + i));
    }
}
void discom(int n, int *a)
{
    printf("The composite elements are: ");
    for (int i = 0; i < n; i++)
    {
        if (prime(*(a + i)) == 1)
        {
            printf("%d ", *(a + i));
        }
    }
}
int main()
{
    int n, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *a;
    a = (int *)malloc(sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (a + i));
    }
    printf("\nWhat do you wanna do?\n");
    printf("1) Insert an element.");
    printf("\n2)Delete and element.");
    printf("\n3)Reverse the elements.");
    printf("\n4)Search an element.");
    printf("\n5)Sort all elements.");
    printf("\n6)Display all the elements.");
    printf("\n7)Display all composite elements.");
    printf("\n8)Quit.\n");
    printf("Enter choice..\n=> ");
    scanf("%d", &choice);
    if (choice > 8)
    {
        printf("Enter valid choice..\n");
    }
    else
    {
        switch (choice)
        {
        case 1:
            insert(n, a);
            break;
        case 2:
            deleteele(n, a);
            break;
        case 3:
            reverse(n, a);
            break;
        case 4:
            search(n, a);
            break;
        case 5:
            sort(n, a);
            break;
        case 6:
            display(n, a);
            break;
        case 7:
            discom(n, a);
            break;
        case 8:
            printf("Exiting..\n");
            break;
        }
    }
    return 0;
}