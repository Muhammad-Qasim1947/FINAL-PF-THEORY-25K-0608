// You are required to develop a system in C language to keep track of all participating groups in the “Coder’s
// Cup” competition. Each group is assigned a set number of tasks. The program intends to include the following
// modules. The solution must be provided using only the mentioned functions. Global variables are not allowed.
// You must use appropriate data types, return types and function arguments.
// a) Module Name: Input().The working of this module goes as follows:
// i- The Input() function is called whenever user wishes to add new participating group
// information (GroupID, GroupName, 5 tasks results).
// ii- Each task’s value must be entered in the form of 0’s or 1’s. If any other value is entered,
// the program must prompt to re-enter.
// a. 0 means that the group become unsuccessful at solving a particular task
// b. 1 means that the group become successful at solving a particular task
// iii- Append the newly taken data into the file named as CompRecord.txt.
// iv- The CompRecord.txt file will have set of records where each record contains
// participating group’s complete information.
// b) Module Name: DisplayWinner(). This module finds and prints all winning groups information.
// Any group is considered to be a winner who has majority of successful attempted all tasks. There
// can be multiple winners.
// c) Module Name: Search().This module displays the status/ details of any given group. The user
// must be allowed to search until he/she enters 0. For example, if user enters 3, the data against
// GroupID = 3 must be displayed that shows GroupName, and its successful and failed tasks.
// HINT:
// - You are allowed to define parameters and return types of these functions as you find appropriate.
// - All above modules are dealing with the data stored in the file.

#include <stdio.h>
#include <string.h>

#define MAX_TASKS 5
#define MAX_NAME 50
#define MAX_GROUPS 100

typedef struct
{
    int GroupID;
    char GroupName[MAX_NAME];
    int Tasks[MAX_TASKS]; // 0 = fail, 1 = success
} Group;

void input(Group groups[], int *count)
{
    if (*count >= MAX_GROUPS)
    {
        printf("Maximum number of groups reached.\n");
        return;
    }

    Group g;
    printf("Enter Group ID : ");
    scanf("%d", &g.GroupID);
    printf("Enter Group Name : ");
    scanf(" %[^\n]", g.GroupName);

    printf("Enter Results For %d Tasks (0 = fail, 1 = success) : ", MAX_TASKS);
    for (int i = 0; i < MAX_TASKS; i++)
    {
        int valid;
        while (!valid)
        {
            printf("Task %d : ", i + 1);
            scanf("%d", &g.Tasks[i]);

            if (g.Tasks[i] == 0 || g.Tasks[i] == 1)
            {
                valid = 1;
            }
            else
            {
                printf("Invalid Please Enter 0 or 1");
            }
        }
    }
    groups[*count] = g;
    (*count++);
    printf("Group information added successfully!\n");
}

void DisplayWinner(Group groups[], int count)
{
    int winnersFound = 0;
    printf("\n--- Winning Groups ---\n");
    for (int i = 0; i < count; i++)
    {
        int sum = 0;
        for (int j = 0; j < MAX_TASKS; j++)
            sum += groups[i].Tasks[j];
        if (sum > MAX_TASKS / 2)
        { // majority success
            winnersFound = 1;
            printf("GroupID: %d, GroupName: %s, Successful Tasks: %d\n",
                   groups[i].GroupID, groups[i].GroupName, sum);
        }
    }
    if (!winnersFound)
        printf("No winners yet.\n");
}

void Search(Group groups[], int count)
{
    int searchID;
    while (1)
    {
        printf("\nEnter GroupID to search (0 to exit): ");
        scanf("%d", &searchID);
        if (searchID == 0)
            break;

        int found = 0;
        for (int i = 0; i < count; i++)
        {
            if (groups[i].GroupID == searchID)
            {
                found = 1;
                printf("GroupID: %d\n", groups[i].GroupID);
                printf("GroupName: %s\n", groups[i].GroupName);
                printf("Task Results: ");
                for (int j = 0; j < MAX_TASKS; j++)
                    printf("%d ", groups[i].Tasks[j]);
                printf("\n");
                break;
            }
        }
        if (!found)
            printf("GroupID %d not found.\n", searchID);
    }
}

int main()
{
    Group groups[MAX_GROUPS];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\nCoder's Cup Menu:\n");
        printf("1. Add Group\n");
        printf("2. Display Winners\n");
        printf("3. Search Group\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Input(groups, &count);
            break;
        case 2:
            DisplayWinner(groups, count);
            break;
        case 3:
            Search(groups, count);
            break;
        case 0:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}