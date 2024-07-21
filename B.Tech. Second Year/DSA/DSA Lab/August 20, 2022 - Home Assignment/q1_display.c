#include <stdio.h>
void display(int n, int a[n]){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
}
int main()
{
    int a[10];
    printf("Enter 10 elements of the array: ");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);
    }
    display(10, a);
    // for (int i = 0; i < 10; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    return 0;
}