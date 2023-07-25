#include <stdio.h>

int main()
{
    int E;
    printf("Input the number of elements to store in the array : ");
    scanf("%i", &E);
    long int N[E];
        printf("Input %i in the array :\n", E);
    for (int i = 0; i < E; i++)
    {
        printf("element - %i : ", i);
        scanf("%ld", &N[i]);
    }
    printf("The values store into the array are : \n");  
    for (int i = 0; i < E; i++)
    {
        printf("%ld ", N[i]);
    }
    printf("\n");
    printf("The values store into the array in reverse are : \n");  
    for (int i = E - 1; i >= 0; i--)
    {
        printf("%ld ", N[i]);
    }
    printf("\n");
}