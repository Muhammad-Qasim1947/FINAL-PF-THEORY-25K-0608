// Output:
// Enter string to remove a
// word from: Programming
// Fundamental
// Enter the word you want
// removed: gram
// After word removed: Proming
// Fundamental

#include <stdio.h>
#include <string.h>
void removeWordFromString(char str[], char word[], char neww[])
{
    int i = 0, j = 0;
    int wordlen = strlen(word);
    int len = strlen(str);

    while (i < len)
    {
        if (strncmp(&str[i], word, wordlen) == 0)
        {
            i += wordlen;
        }
        else
        {
            neww[j++] = str[i++];
        }
    }

    neww[j] = '\0'; // terminate the new string
}
int main()
{
    char str[100], neww[100], word[100];

    printf("Enter string to remove a word from:");
    gets(str);

    printf("\nEnter the word you want removed: ");
    gets(word);

    removeWordFromString(str, word, neww);

    printf("\nAfter word removed: %s\n", neww);

    return 0;
}