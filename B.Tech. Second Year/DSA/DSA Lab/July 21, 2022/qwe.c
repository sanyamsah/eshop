#include <stdio.h>

int main()
{
 int a[100], i, size,j,start, end,count = 0;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    for(i = 0; i < size ; i++){
        scanf("%d", &a[i]);
    }
    printf("Input the start and end: ");
    scanf("%d %d", &start , &end);
    
   for(i = 0; i < size ; i++){
        if(a[i] == start){
            for(j = 0 ; a[j] != end ; j++){
                count++;
            }
        }
    }
      
   
    printf("Number of elements betweeen start and end is = %d", count);
    
    return 0;
}