#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatStrings(char *current, char *newString)
{
    int lenCurrent = 0;

    if (current != NULL)
    {
        lenCurrent = strlen(current);
    }

    int lenNew = strlen(newString);

    // Allocate memory for combined string (+1 for null terminator)
    char *result = malloc(lenCurrent + lenNew + 1);

    if (result == NULL)
    {
        printf("Memory Allocation Failed\n");
        return current; // keep old string if allocation fails
    }

    // Copy old string if exists
    if (current != NULL)
    {
        strcpy(result, current);
    }
    else
    {
        result[0] = '\0';
    }

    // Concatenate new string
    strcat(result, newString);

    // Free previous string
    if (current != NULL)
    {
        free(current);
    }

    return result;
}

int main()
{
    char input[100];
    char *allStrings = NULL;

    while (1)
    {
        printf("Enter a string to concatenate (or Q to quit): ");
        scanf(" %[^\n]", input);

        if (strcmp(input, "Q") == 0 || strcmp(input, "q") == 0)
        {
            break;
        }

        allStrings = concatStrings(allStrings, input);

        printf("Current Concatenated String: %s\n", allStrings);
    }

    if (allStrings != NULL)
    {
        printf("\nFinal Concatenated String: %s\n", allStrings);
        free(allStrings); // free final memory
    }
    else
    {
        printf("No strings were entered.\n");
    }

    return 0;
}
