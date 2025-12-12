#include <stdio.h>

int foo(int num)
{
    if (num < 10)
    {
        return num;
    }
    
    int sum = num / 10 + foo(num % 10);

    if (sum > 9)
    {
        return sum / 10 + foo(sum % 10);
    }
    else
    {
        return sum;
    }
}

int main()
{
    printf("Sum : %d\n", foo(456));
    printf("Sum : %d", foo(97));
    return 0;
}


