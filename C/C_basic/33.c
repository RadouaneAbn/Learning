#include <stdio.h>

int main()
{
    int N[5];
    printf("Input five integers:\n");

    for (int i = 0; i < 5; i++) //input loop
    {
        scanf("%i", &N[i]);
    }

    int j, max = 0, pos = 0;
    for (j = 0; j < 5; j++)
    {
        if (N[j] > max)
        {
            max = N[j];
            pos = j + 1;
        }
    }

    printf("Highest value: %i\n", max);
    printf("Position: %i\n", pos);
}