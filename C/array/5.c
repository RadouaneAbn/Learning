#include <stdio.h>

int main()
{
    int x = 0;
    int E;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%i", &E);
    printf("Input %i elements in the array : \n", E);
    long int N[E];

    for (int i = 0; i < E; i++)
    {
        printf("element - %i : ", i);
        scanf("%ld", &N[i]);
    }

    for (int j = 0; j < E; j++)
    {
        for (int k = 0; k < E; k++)
        {
            if (j != k)
            {
                if (N[j] == N[k])
                {
                    x++;
                }
            }
            
        }
    }
    printf("Total number of duplicate elements found in the array is : %i\n", x/2);
}