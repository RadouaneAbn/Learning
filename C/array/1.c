#include <stdio.h>

int main()
{
    long int N[10];
    for (int i = 0; i < 10; i++)
    {
        printf("element - %i : ", i);
        scanf("%ld", &N[i]);
    }
    printf("Element in array are : ");  
    for (int i = 0; i < 10; i++)
    {
        printf("%ld ", N[i]);
    }
    printf("\n");
}