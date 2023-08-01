#include <stdio.h>

int main()
{
    int a, b, sum = 0;
    printf("Input the first integer: ");
    scanf("%i", &a);
    printf("Input the second integer: ");
    scanf("%i", &b);

    for (int i = a; i <= b; i++)
    {
        if ((i % 17) != 0)
        {
            sum = sum + i;
        }
    }
    printf("Sim: %i\n", sum);
}