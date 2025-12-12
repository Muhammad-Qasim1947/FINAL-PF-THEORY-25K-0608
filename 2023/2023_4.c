// Implement a “C program” that dynamically allocates memory for strings and concatenates them. The program
// should perform the following steps:
// 1. Input:
// • Prompt the user to enter two strings of varying lengths.
// • Use dynamic memory allocation to create char arrays to store the input strings.
// 2. Functionality:
// • Create a function that takes the two input strings and dynamically allocates memory to concatenate
// them into a new string.
// • The concatenated string should have sufficient space for the combined strings and the nullterminator.
// • Repetitively take user inputs and concatenate until the users stops it with ‘Q’.
// • All new inputs must be concatenated with the previous data. Do not over-write previous data in the
// variables. (Hint: Something related to re-allocation might help)
// 3. Output: Display the original input strings and the concatenated result.
// 4. Error Handling: Implement appropriate error handling. Check for memory allocation failures and inform the
// user if there's an issue.
// 5. Testing: Test your program with strings of different lengths to ensure correct memory allocation,
// concatenation, and freeing of memory.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char *current, char *new)
{
    int currentlength = 0 ;
    if (current != NULL)
    {
        currentlength = strlen(current);
    }
    int newlen;
    newlen = strlen(new);

    char *result;
    result = malloc(currentlength + newlen + 1);

    if (result == NULL)
    {
        printf("Memory Allocation Failed\n");
        return current; // keep old string if allocation fails
    }

    if (current != NULL)
    {
        strcpy(result, current);
    }
    else
    {
        result[0] = '\0';
    }

    strcat(result, new);

    if (current != NULL)
    {
        free(current);
    }

    return result;
}

int main()
{
    char input[1000];
    char *allstrings = NULL;

    while (1)
    {
        printf("\nEnter The String ( Q to quit ) : ");
        scanf(" %[^\n]", input);

        if ((strcmp(input, 'q')==0) || (strcmp(input, 'Q')==0))
        {
            printf("Exiting.....");
            break;
        }

        allstrings = concat(allstrings, input);
    }
}