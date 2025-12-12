// Imagine you are tasked with developing a management system for a library's CD collection. Each CD
// has a unique ID, title, artist name, genre, and the number of tracks. The system needs to allow users
// to:
// ● Add new CDs dynamically.
// ● Delete CDs by their ID.
// ● Search for CDs by title .
// ● Update CD details.
// To enhance functionality, the system should also allow users to:
// ● Sort CDs by title, artist name, or number of tracks using a simple sorting algorithm
// ● You must use structures to represent individual CDs and dynamic memory allocation to
// manage a collection of CDs that grows or shrinks based on user actions.
// ● Also write a method to print the data set in following manner after any operation is performed
// on the dataset.
// Sorting Task:
// Write a program that sorts the collection by:
// ● Title (alphabetically).
// ● Artist name (alphabetically).
// ● Number of tracks (ascending).
// Searching Task:
// After sorting, implement a simple search algorithm to find a CD by its title or artist name. If a match
// is found, display the CD details; otherwise, return a message indicating no match.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char title[50];
    char artist[50];
    char genre[50];
    int numoftrack;
} collection;

// Function to print all CDs
void printcds(collection *cds, int count)
{
    if (count == 0)
    {
        printf("No CDs in the collection.\n");
        return;
    }

    printf("\nThe CDs in Library are:\n");
    for (int i = 0; i < count; i++)
    {
        printf("\nCD %d:\n", i + 1);
        printf("ID: %d\n", cds[i].id);
        printf("Title: %s\n", cds[i].title);
        printf("Artist: %s\n", cds[i].artist);
        printf("Genre: %s\n", cds[i].genre);
        printf("Num Of Tracks: %d\n", cds[i].numoftrack);
    }
}

// Function to delete a CD by ID
int deletecds(collection **cds, int *count)
{
    int id;
    printf("Enter the CD ID you want to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++)
    {
        if ((*cds)[i].id == id)
        {
            for (int j = i; j < *count - 1; j++)
            {
                (*cds)[j] = (*cds)[j + 1];
            }
            (*count)--;

            *cds = realloc(*cds, (*count) * sizeof(collection));
            if (*cds == NULL && *count > 0)
            {
                printf("Memory reallocation failed!\n");
                exit(1);
            }
            return 1; // success
        }
    }
    return 0; // not found
}

// Function to search CD by title
void search(collection *cds, int count)
{
    char title[100];
    printf("Enter the Title Name to search: ");
    scanf(" %[^\n]", title);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(cds[i].title, title) == 0)
        {
            printf("\nCD Found:\n");
            printf("ID: %d\n", cds[i].id);
            printf("Title: %s\n", cds[i].title);
            printf("Artist: %s\n", cds[i].artist);
            printf("Genre: %s\n", cds[i].genre);
            printf("Num Of Tracks: %d\n", cds[i].numoftrack);
            found = 1;
        }
    }
    if (!found)
    {
        printf("No CD found with the title '%s'.\n", title);
    }
}

// Function to update CD by ID
void updateCD(collection *cds, int count)
{
    int id;
    printf("Enter the ID of the CD to update: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (cds[i].id == id)
        {
            printf("Updating CD with ID %d:\n", id);
            printf("Enter new Title: ");
            scanf(" %[^\n]", cds[i].title);
            printf("Enter new Artist: ");
            scanf(" %[^\n]", cds[i].artist);
            printf("Enter new Genre: ");
            scanf(" %[^\n]", cds[i].genre);
            printf("Enter new Number of Tracks: ");
            scanf("%d", &cds[i].numoftrack);
            found = 1;
            printf("CD updated successfully!\n");
            break;
        }
    }

    if (!found)
    {
        printf("CD with ID %d not found.\n", id);
    }
}

int main()
{
    collection *cds = NULL;
    int count = 0;
    int choice;

    do
    {
        printf("\n--- CD Management Menu ---\n");
        printf("1. Add CD\n2. Print CDs\n3. Delete CD\n4. Search CD by Title\n5. Update CD\n6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Add CD
            cds = realloc(cds, (count + 1) * sizeof(collection));
            if (cds == NULL)
            {
                printf("Memory allocation failed!\n");
                return 1;
            }

            printf("Enter CD ID: ");
            scanf("%d", &cds[count].id);
            printf("Enter Title: ");
            scanf(" %[^\n]", cds[count].title);
            printf("Enter Artist: ");
            scanf(" %[^\n]", cds[count].artist);
            printf("Enter Genre: ");
            scanf(" %[^\n]", cds[count].genre);
            printf("Enter Number of Tracks: ");
            scanf("%d", &cds[count].numoftrack);

            count++;
            printf("CD added successfully!\n");
            break;

        case 2: // Print CDs
            printcds(cds, count);
            break;

        case 3: // Delete CD
            if (deletecds(&cds, &count))
                printf("CD deleted successfully!\n");
            else
                printf("CD not found!\n");
            break;

        case 4: // Search CD
            search(cds, count);
            break;

        case 5: // Update CD
            updateCD(cds, count);
            break;

        case 6: // Exit
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid Choice!\n");
            break;
        }
    } while (choice != 6);

    free(cds); // Free dynamic memory
    return 0;
}
