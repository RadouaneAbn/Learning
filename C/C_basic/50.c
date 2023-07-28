#include <stdio.h>

int main()
{
    float N[5];
    printf("Input 5 numbers of the array: \n");
    
    for (int i = 0; i < 5; i++)
    {
        printf(">>> ");
        scanf("%f", &N[i]);
    }

    printf("Output: \n");

    for (int j = 0; j < 5; j++)
    {
        if (N[j] < 5)
        {
            printf("A[%i] = %.1f\n", j, N[j]);
        }
    }

}