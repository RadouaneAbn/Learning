#include <stdio.h>

int main()
{
    int N[5];
    printf("Input the 5 numbers of the array:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Num %i: ", i + 1);
        scanf("%i", &N[i]);
        if (N[i] <= 0)
        {
            N[i] = 100;
        }
    }

    printf("Array values are: \n");
    for (int j = 0; j < 5; j++)
    {
        printf("n[%i] = %i\n", j, N[j]);
    }
}