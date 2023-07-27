#include <stdio.h>

int main()
{
    int n, P = 0, N = 0;
    char* L[5] = {"first", "second", "third", "fourth", "fifth"};
    // char L[5][20] = {"first", "second", "third", "fourth", "fifth"};
    
    for (int i = 0; i < 5; i++)
    {
        printf("Input the %s number: ", L[i]);
        scanf("%d", &n);
        
        if (n >= 0)
        {
            P++;
        }
        else
        {
            N++;
        }
    }
    printf("\nNumber of positive number: %i\n", P);
    printf("Number of negative number: %i\n", N);
}