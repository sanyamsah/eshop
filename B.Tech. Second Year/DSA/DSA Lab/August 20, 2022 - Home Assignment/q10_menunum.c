#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int oddeven(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int prime(int n)
{
    int flag = 0;
    if (n == 1 || n == 0)
    {
        flag = 2;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

int palindrome(int n)
{
    int temp, rev = 0, rem;
    temp = n;
    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    if (temp == rev)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int armstrong(int n)
{
    int p = 0, rem, sum = 0;
    int temp1, temp2;
    temp1 = temp2 = n;
    while (temp1 != 0)
    {
        temp1 /= 10;
        p++;
    }
    while (n != 0)
    {
        rem = n % 10;
        sum = sum + pow(rem, p);
        n /= 10;
    }
    if (temp2 == sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, a;
    printf("\nEnter a number: ");
    scanf("%d", &n);
    do
    {
        printf("What do you wanna perform?\n");
        printf("(1) Check whether Odd or Even.\n");
        printf("(2) Check whether Prime or Composite.\n");
        printf("(3) Check whether Palindrome or not.\n");
        printf("(4) Check whether Armstrong or not.\n");
        printf("(5) QUIT.\n");
        printf("Enter your choice..\n");
        printf("=> ");
        scanf("%d", &a);
        if (a < 1 || a > 5)
        {
            printf("Enter valid choice.\n");
        }
        switch (a)
        {
        case 1:
            if (oddeven(n) == 1)
            {
                printf("=> EVEN.\n");
            }
            else
            {
                printf("=> ODD.\n");
            }
            break;
        case 2:
            if (prime(n) == 2)
            {
                printf("=> Neither Prime, Nor Composite.\n");
            }
            else if (prime(n) == 1)
            {
                printf("=> COMPOSITE.\n");
            }
            else
            {
                printf("=> PRIME.\n");
            }
            break;
        case 3:
            if (palindrome(n) == 1)
            {
                printf("=> PALINDROME.\n");
            }
            else
            {
                printf("=> NOT PALINDROME.\n");
            }
            break;
        case 4:
            if (armstrong(n) == 1)
            {
                printf("=> ARMSTRONG.\n");
            }
            else
            {
                printf("=> NOT ARMSTRONG.\n");
            }
            break;
        }
        printf("\n");
    } while (a != 5);
    return 0;
}