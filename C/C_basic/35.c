#include <stdio.h>

int main()
{
    float a, b;
    printf("Input a pair of numbers (for example 10,2 : 2,10):\n");
    printf("Input first number of the pair: ");
    scanf("%f", &a);
    printf("Input second number of the pair: ");
    scanf("%f", &b);

    if (a == b)
    {
        printf("The pair is equal.\n");
    }

    else if (a < b)
    {
        printf("The pair is in ascending order!\n");
    }

    else
    {
        printf("The pair is in descending order!\n");
    }
}