#include <stdio.h>
void nonzero(int x, int mat[][x])
{
  int count = 0;
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < x; j++)
    {
      if (mat[i][j])
      {
        count += 1;
      }
    }
  }
  printf("The total nonzero elements are: %d\n", count);
}
void abovediagonal(int y, int mat[][y])
{
  int sum = 0;
  for (int i = 0; i < y; i++)
  {
    for (int j = 0; j < y; j++)
    {
      if (i < j)
      {
        sum += mat[i][j];
      }
    }
  }
  printf("The sum of all the elements above diagonal is: %d\n", sum);
}
void belowminor(int z, int mat[][z])
{
  printf("Elements below minor diagonal are: ");
  for (int i = 0; i < z; i++)
  {
    for (int j = 0; j < z; j++)
    {
      if (i + j >= z)
      {
        printf("%d ", mat[i][j]);
      }
    }
  }
  printf("\n");
}
void product(int k, int mat[][k])
{
  int product = 1;
  for (int i = 0; i < k; i++)
  {
    for (int j = 0; j < k; j++)
    {
      if (i == j)
      {
        product = product * mat[i][j];
      }
    }
  }
  printf("The product of the main diagonal elements of the matrix is: %d", product);
}
int main()
{
  int n;
  printf("Enter the number of rows in square matrix: ");
  scanf("%d", &n);
  int arr[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &arr[i][j]);
    }
  }
  nonzero(n, arr);
  abovediagonal(n, arr);
  belowminor(n, arr);
  product(n, arr);
  return 0;
}