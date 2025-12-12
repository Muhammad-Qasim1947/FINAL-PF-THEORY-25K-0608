#include <stdio.h>
int main()
{
    char str[] = "Programming";
    char *ptr = str;
    printf("%c\n", *(ptr + 4));
    printf("%s\n", ptr + 5);
    return 0;
}