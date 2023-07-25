#include <stdio.h>

int main()
{
    int E;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%i", &E);
    printf("Input %i elements in the array : \n", E);
    long int N[E];
    long int M[E];

    for (int i = 0; i < E; i++)
    {
        printf("element - %i : ", i);
        scanf("%ld", &N[i]);
    }

    for (int j = 0; j < E; j++)
    {
        M[j] = N[j];
    }

    printf("The elements stored in the first array are : \n");
    for (int k = 0; k < E; k++)
    {
        printf("%ld ", N[k]);
    }
    printf("\n");
    printf("The elements copied into the second array are : \n");
    for (int l = 0; l < E; l++)
    {
        printf("%ld ", M[l]);
    }
    printf("\n");
}