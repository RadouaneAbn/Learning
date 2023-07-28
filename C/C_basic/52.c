#include <stdio.h>

int main()
{
    int n, S, P, i, k;
    printf("Input the length of the array: ");
    scanf("%i", &n);
    printf("Input the array elements:\n");

    int N[n];
    for (i = 0; i < n; i++)
    {
        scanf("%i", &N[i]);
    }

    S = N[0];
    for (k = 0; k < n; k++)
    {
        if (S > N[k])
        {
            S = N[k];
            P = k;
        }
    }

    printf("Smallest value: %i\n", S);
    printf("Position of the element: %i\n", P);
}