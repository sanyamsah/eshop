#include<stdio.h>
int main(){
    int n, i, j, count=0, max=0, rep;
    printf("Enter the number of array elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: ");
     for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nThe array elements are..\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
            if (count > max)
            {
                max = count;
                rep = a[i];
            }
        }
        count = 0;
    }
    printf("Maximum times repeated element: %d \n", rep);
}