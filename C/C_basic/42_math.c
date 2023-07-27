#include <stdio.h>
#include <math.h>

int main()
{
    int S, c;
    printf("Input nuber of lines: ");

    while (scanf("%i", &c) == 1)
    {
        if (c > 0)
        {
            for (int i = 1; i <= c; i++)
            {
                for (int j = 1; j <= 3; j++)
                {
                    S = pow(i, j);
                    printf("%i ", S);
                }

                printf("\n");
            }
            break;
        }
        else
        {
            printf("Invalid input, input a valide number: ");

        }
    }
}