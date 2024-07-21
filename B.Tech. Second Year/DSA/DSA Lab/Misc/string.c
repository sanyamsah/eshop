#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapsort(char **p, int a)
{
    char *temp = (char *)malloc(sizeof(char));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a - 1 - i; j++)
        {
            if (strcmp(p[j], p[j + 1]) > 0)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int a;
    printf("Enter the number of names in the array: ");
    scanf("%d", &a);
    char **s, *temp;
    s = (char **)malloc(sizeof(char *));
    for (int i = 0; i < 50; i++)
    {
        s[i] = (char *)malloc(sizeof(char));
    }

    printf("Enter the names: ");
    for (int i = 0; i < a; i++)
    {
        scanf("%s", s[i]);
    }
    swapsort(s, a);
    for (int i = 0; i < a; i++)
    {
        printf("%s ", s[i]);
    }
}