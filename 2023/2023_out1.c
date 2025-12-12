// Output:
// Enter size of array: 5
// Enter 5 elements in array:
// 1 -2 3 -1 9
// Minimum value in array : -2
// Maximum value in array : 9

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
int *getMinMax(int *array, const int size);
int main()
{
    int array[MAX_SIZE] = {1, -2, 3, -1, 9};
    int *resultArr = getMinMax(array, MAX_SIZE);
    printf("Min value in array: %d\n", resultArr[0]);
    printf("Max value in array: %d\n", resultArr[1]);
    free(resultArr);
    return 0;
}
int *getMinMax(int *numbers, const int size)
{
    int *result = malloc(2 * sizeof(int));

    if (result == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }

    int min = numbers[0];
    int max = numbers[0];

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }

        if (numbers[i] < min)
        {
            min = numbers[i];
        }
    }

    result[0] = min ;
    result[1] = max ;

    return result ;
}
