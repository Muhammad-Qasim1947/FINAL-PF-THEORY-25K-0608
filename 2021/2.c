// Write Recursive Function To Reverse The Input Sentence :

#include <stdio.h>
#include <string.h>

void reverse(char string[], int start)
{
    int len = strlen(string);

    if (start >= len)
    {
        return;
    }

    int end = start;

    while (string[end] != ' ' && string[end] != '\0')
    {
        end++;
    }

    reverse(string, end + 1);

    for (int i = start; i < end; i++)
        printf("%c", string[i]);

    if (end < len)
        printf(" ");
}

int main()
{
    char string[50];
    printf("Enter The String : ");
    scanf(" %[^\n]", string);

    printf("Reversed sentence: ");
    reverse(string, 0);

    printf("\n");
}