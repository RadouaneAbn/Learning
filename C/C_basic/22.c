#include <stdio.h>

int main()
{
    int n, X = 0;
    char* L[5] = {"first", "second", "third", "fourth", "fifth"};
    
    for (int i = 0; i < 5; i++)
    {
        printf("Input the %s number: ", L[i]);
        scanf("%d", &n);
        if ((n % 2) != 0)
        {
            X = X + n;
        }
    }
    printf("Sum of all odd values: %d\n", X);
}