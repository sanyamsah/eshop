#include <stdio.h>
int main()
{
    int n, mode, sum = 0, i, j, temp, med1, med2, count = 0, max = 0;
    float mean, median;
    printf("Enter the number of elements elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    mean = (float)sum / n;
    printf("Mean = %.2f\n", mean);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            if (a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    if (n % 2 == 0)
    {
        med1 = (n + 1) / 2;
        med2 = med1 + 1;
        median = (float)(a[med1 - 1] + a[med2 - 1]) / 2;
    }
    else
    {
        med1 = (n + 1) / 2;
        median = a[med1 - 1];
    }
    printf("Median=%.2f\n", median);
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
                mode = a[i];
            }
        }
        count = 0;
    }
    printf("Mode = %d \n", mode);
}
