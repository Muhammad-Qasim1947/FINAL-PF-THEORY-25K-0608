#include <stdio.h>
void my_print(char *str)
{
    char *ptr;
    int i, j;
    for (i = 0; *(str + i) != '\0'; i++)
    {
        ptr = str;
        for (j = 0; j < (5 - i); j++)
        {
            printf("%c", *(ptr + j));
        }
        printf("\n");
    }
}
int main()
{
    char text[] = "ABCDE";
    my_print(text);
    return 0;
}