#include <stdio.h>

int main()
{
    int i, j, k, l, t;
    int E;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%i", &E);
    printf("Input %i elements in the array : \n", E);
    
    long int N[E];
    int M[E];

    for (l = 0; l < E; l++)
    {
        M[l] = 0;
    }
    
    for (i = 0; i < E; i++)
    {
        printf("element - %i : ", i);
        scanf("%ld", &N[i]);
    }

    for (j = 0; j < E; j++)
    {
        for (k = i + 1; k < E; k++)
        {
            if (N[j] == N[k])
            {
                M[j]++;
            }
            

        }
    }
    printf("The unique elements found in the array are:\n");
    for (t = 0; t < E; t++)
    {
        if (M[t] != 0)
        {
            printf("%ld ", N[t]);
        }
    }
    printf("\n");
}
