#include <stdio.h>
int mysteryRec(int a, int b)
{
    if (b == 1)
        return a;
    else
        return a + mysteryRec(a, b - 1);
}
int main(void)
{
    printf("The result is %u\n",mysteryRec(4, 5));
    return 0;
}