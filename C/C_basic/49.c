#include <stdio.h>

int main()
{
    int A[7];
    printf("Input the first number of the array: ");
    scanf("%i", &A[0]);

    for (int i = 1; i <= 7; i++)
    {
        A[i] = A[i - 1] * 3;
    }
    
    printf("The output: \n");
    for (int j = 0; j < 7; j++)
    {
        printf("n[%i] = %i\n", j, A[j]);
    }
}