// Implement a recursive function given below to convert a non-negative integer number to its English
// word representation:
// [Hint: You can create global variables or arrays to implement]
// Here, “num” ranges between 0 to 10000 so handle cases according to it.
// Sample Input: num= 798
// Output: Seven Hundred Ninety Eight
// Function: (Implement Function Definition given below)

#include <stdio.h>
#include <string.h>

char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char *tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                "Sixty", "Seventy", "Eighty", "Ninety"};

void numbertowords(int num)
{
    if (num == 0)
    {
        printf("Zero");
        return;
    }

    if (num >= 1000)
    {
        printf("%s Thousand ", ones[num / 1000]);
        if (num % 1000 != 0)
        {
            numbertowords(num % 1000);
        }
    }
    else if (num >= 100)
    {
        printf("%s Hundred ", ones[num / 100]);
        if (num % 100 != 0)
        {
            numbertowords(num % 100);
        }
    }
    else if (num >= 20)
    {
        printf("%s ", tens[num / 10]);
        if (num % 10 != 0)
        {
            numbertowords(num % 10);
        }
    }
    else if (num >= 10)
    {
        printf("%s ", teens[num - 10]);
    }
    else if (num > 0)
    {
        printf("%s ", ones[num]);
    }
}

int main()
{
    int num;
    printf("Enter The Number To Change In Alphabets : ");
    scanf("%d", &num);

    if (num < 0 || num > 10000) {
        printf("Number out of range!\n");
        return 1;
    }

    numbertowords(num);
    printf("\n");
    return 0 ;
}