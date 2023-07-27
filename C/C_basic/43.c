#include <stdio.h>

int main()
{
    int p, q, C = 1;
    printf("Input number of lines: ");
    scanf("%i", &p);
    printf("Number of charachter in a line: ");
    scanf("%i", &q);

    for (int i = 0; i < p; i++)
    {
        for (int j = 1; j <= q; j++)
        {
            printf("%i ", C);
            C++;
        }
        printf("\n");
    }
}