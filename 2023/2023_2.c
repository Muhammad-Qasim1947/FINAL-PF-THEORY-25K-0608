// You need to write two functions for user authentication with encryption in C Language:
// Part A. void encrypt(*usernames, *passwords): This function takes two pointer arrays as arguments: usernames:
// An array of 100 strings containing user names, and passwords: An array of 100 strings containing passwords.
// Strings are null (‘\0’) terminated.
// For each username and password pair, the function encrypts them using the below method:
// • Each character in the string is replaced by another character that is i positions ahead in the alphabet.
// • i is determined by the index of the string in the usernames array (e.g., first string element uses i=0, second
// element uses i=1, etc.).
// Part B. int find(*usernames, *passwords, *search_username, *search_password): This function takes four
// arguments. The function searches in the encrypted usernames and passwords arrays for a matching pair
// corresponding to the provided search_username and search_password (un-encrypted). Function returns 1 if a
// matching username and password pair are found, 0 otherwise

#include <stdio.h>

void encrypted(char *usernames[], char *passwords[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; usernames[i][j] != '\0'; j++)
            usernames[i][j] += i; // shift by index
        for (int j = 0; passwords[i][j] != '\0'; j++)
            passwords[i][j] += i; // shift by index
    }
}

int search(char *usernames[], char *passwords[], int n, char *searchname, char *searchpass)
{
    for (int i = 0; i < n; i++)
    {
        int match = 1;

        // Compare username
        for (int j = 0; usernames[i][j] != '\0' || searchname[j] != '\0' ; j++)
        {
            if (searchname[j] == '\0' && usernames[i][j] == '\0') break;
            if (searchname[j] + i != usernames[i][j])
            {
                match = 0;
                break;
            }
        }

        // Compare password only if username matched
        if (match)
        {
            for (int j = 0; passwords[i][j] != '\0' || searchpass[j] != '\0' ; j++)
            {
                if (searchpass[j] == '\0' && passwords[i][j] == '\0') break;
                if (searchpass[j] + i != passwords[i][j])
                {
                    match = 0;
                    break;
                }
            }
        }

        if (match) return 1; // found
    }

    return 0; // not found
}

int main()
{
    int n;
    printf("Enter The Number Of Users: ");
    scanf("%d", &n);

    char name[100][50];     // 100 users, max 50 chars each
    char password[100][50];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Username %d: ", i + 1);
        scanf(" %[^\n]", name[i]);

        printf("Enter Password %d: ", i + 1);
        scanf(" %[^\n]", password[i]);
    }

    // Encrypt all usernames and passwords
    encrypted(name, password, n);

    char searchname[50];
    char searchpass[50];

    printf("\nEnter The Name To Search: ");
    scanf(" %[^\n]", searchname);

    printf("Enter The Password To Search: ");
    scanf(" %[^\n]", searchpass);

    if (search(name, password, n, searchname, searchpass))
        printf("\nUser found!\n");
    else
        printf("\nUser not found.\n");

    return 0;
}
