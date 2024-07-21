#include <stdio.h>
#include <string.h>
int main()
{
    int count = 0;
    char a[30], b;
    printf("Enter a string: ");
    gets(a);
    printf("Enter the character: ");
    scanf("%c", &b);
    int i = 0;
    while (a[i] != '\0')
    {
        if (a[i] == b)
        {
            count++;
        }
        i++;
    }
    printf("%d", count);
    return 0;
}