#include <stdio.h>
int main()
{
    int x = 7;
    printf("%d\n", (x > 5) && (x < 10));
    printf("%d\n", (x < 5) || (x == 7));
    return 0;
}
