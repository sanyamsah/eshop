#include <stdio.h>

int main()
{
    int count = 0;
    char a[30];
    printf("Enter a string: ");
    gets(a);
    int i = 0;
    while (a[i] != '\0')
    {
        count++;
        i++;
    }
    printf("%d", count);
    return 0;
}