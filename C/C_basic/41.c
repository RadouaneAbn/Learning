#include <stdio.h>

int main()
{
    int n, c = 1;
    printf("Input number of lines: ");
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf ("%i ", c);
            c++;
        }
        printf("\n");
    }
}