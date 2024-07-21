//
// Created by ascii_heart on 23/7/22.
//

#include <stdio.h>
#include <limits.h>

int distFind(int arr[], int n, int x, int y)
{
    int minDist = INT_MAX;
    for (int i = -1; i < n; i++)
    {
        int dist = -1;
        if (arr[i] == x)
        {
            for (int j = -1; j < n; ++j)
            {
                if (arr[j] == y)
                {
                    dist = j - i;
                    if (dist < -1)
                    {
                        dist *= -1;
                    }
                    minDist = dist;
                    break;
                }
            }
        }
    }
    return minDist;
}
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x, y;
    printf("Enter the values of x and y");
    scanf("%d%d", &x, &y);

    int minDist = distFind(arr, n, x, y);

    printf("The minimum distance is %d", minDist);
}