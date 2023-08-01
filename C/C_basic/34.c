#include <stdio.h>

int main()
{
    int a, b;
    printf("Input a pair of numbers (for example 10, 2).");
    printf("\nInput first number: ");
    scanf("%i", &a);
    printf("Input second number: ");
    scanf("%i", &b);

    if ( a > b)
    {
        int tmp;
        tmp = b;
        b = a;
        a = tmp;
    }

    int T = 0;
    printf("List of odd numbers:\n");
    for ( int i = a; i <= b; i++)
    {
        if ((i % 2) != 0)
        {
            printf("%i\n", i);
            T = T + i;
        }
    }
    printf("Sum = %i\n", T);
}