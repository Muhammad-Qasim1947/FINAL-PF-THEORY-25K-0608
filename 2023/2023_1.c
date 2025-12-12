// Consider a coinage system consisting of n coins. Each coin has a positive integer value. Your task is to produce a
// sum of money x using the available coins in such a way that the number of coins is minimal. For example, if the
// coins are { 1, 5, 7 } and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
// Write a recursive function int foo( … ), that returns the minimal number of coins to make the sum x.
// You may assume that the input variables {arr, n , x} are globally defined. You may write the function definition of
// foo with the parameters that you think are appropriate.
// SAMPLE INPUT 1: SAMPLE INPUT 2:
// n = 3
// x = 11
// arr[n] = {1, 5, 7}
// n = 4
// x = 26
// arr[n] = {2, 4, 8, 9}
// SAMPLE OUTPUT 1: SAMPLE OUTPUT 2:
// 3 4

#include <stdio.h>

// Global variables
int arr[100]; // coin values
int n;        // number of coins
int x;        // target sum

// Recursive function
int foo(int remainingSum)
{
    if (remainingSum == 0)
    {
        return 0;
    }

    int minCoins = 1000000; // a very large number

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= remainingSum)
        {
            int res = foo(remainingSum - arr[i]);
            if (res + 1 < minCoins)
            {
                minCoins = res + 1;
            }
        }
    }

    return minCoins;
}

int main()
{
    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter the coin values: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &x);

    int result = foo(x);

    if (result >= 1000000)
    {
        printf("It is not possible to make the sum with the given coins.\n");
    }
    else
    {
        printf("Minimum coins needed: %d\n", result);
    }

    return 0;
}
