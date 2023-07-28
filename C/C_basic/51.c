#include <stdio.h>
// the first way
int main()
{
        int N[6], n = 0;
    printf("Input the 6 members of the array:\n");
    for (int i = 0; i < 6; i++)
    {
        printf(">>> ");
        scanf("%i", &N[i]);
    }

    for (int j = 5; j >= 0; j--)
    {
        printf("array_n[%i] = %i\n", n, N[j]);
        n++;
    }
}

/*  the second way
int main()
{
    int N[6], M[6];
    printf("Input the 6 members of the array:\n");
    for (int i = 0; i < 6; i++)
    {
        printf(">>> ");
        scanf("%i", &N[i]);
    }

    for (int j = 5, k = 0; j >= 0, k < 6; j--, k++)
    {
        M[k] = N[j];
    }

    for (int t = 0; t < 6; t++)
    {
        printf("array_n[%i] = %i\n", t, M[t]);
    }
}
*/