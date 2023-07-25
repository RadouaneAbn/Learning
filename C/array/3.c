#include <stdio.h>

int main()
{
    long int sum = 0;
    int E;
    printf("Input the number of elements to be stored in the array : ");
    scanf("%i", &E);
    long int N[E];
    printf("Input %i in the array :\n", E);
    for (int i = 0; i < E; i++)
    {
        printf("element - %i : ", i);
        scanf("%ld", &N[i]);
        sum = sum + N[i];
    }
    printf("Sum of all elements stored in the array is : %ld\n", sum);
    
}