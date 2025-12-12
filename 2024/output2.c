#include <stdio.h>
void processNums(int nums[], int n)
{
    int i = -1, j;
    for (j = 0; j < n; ++j)
    {
        if (nums[j] == 1)
        {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
}
int main()
{
    int arr[] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0};
    int n = 10;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
        printf("\n");

        processNums(arr, n);
    

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
