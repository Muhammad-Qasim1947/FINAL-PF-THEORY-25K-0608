// Q4. Write a C program that calculates the number of 1s in the entire 2D Array of MxN size using
// recursion. You will be rewarded ZERO marks if you use loops by any means in the program.
// [30 minutes, 20 Points]

// output = 5

#include <stdio.h>

void inputArray(int arr[][100], int i, int j, int M, int N)
{
    if (i == M)
        return ; // all rows done
    if (j == N)
    {
        inputArray(arr, i + 1, 0, M, N); // move to next row
        return;
    }
    printf("Enter element at [%d][%d]: ", i, j);
    scanf("%d", &arr[i][j]);
    inputArray(arr, i, j + 1, M, N); // next column
}

int countone(int arr[][100], int i, int j, int M, int N)
{
    if (i == M)
        return 0; // all rows done
    if (j == N)
    {
        return countone(arr, i + 1, 0, M, N); // move to next row
        
    }

    int count = 0 ;
    if (arr[i][j] == 1)
    {
        count = 1 ;
    }

    return count + countone(arr , i , j+1 , M , N);
    
}

int main()
{
    int m, n;
    printf("Enter The Number Of Rows : ");
    scanf("%d", &m);
    printf("Enter The Number Od Columns : ");
    scanf("%d", &n);

    int arr[100][100];

    inputArray(arr, 0, 0, m, n);

    int result = countone(arr, 0, 0, m, n);
    printf("Number Of Ones : %d\n", result);

    return 0;
}