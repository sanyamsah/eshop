#include <stdio.h>
#include<string.h>
#include <math.h>
int main()
{
    int i, count;
    printf("Enter a string: ");
    char a[50];
    gets(a);
   count=strlen(a);
    int num=pow(2, count)-1;
    printf("%d\n", count);
    printf("%d\n", num);
    
}