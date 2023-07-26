#include <stdio.h>

int main()
{
    float A, C = 0;
    int n, P = 0;
    char* L[5] = {"first", "second", "third", "fourth", "fifth"};
    
    for (int i = 0; i < 5; i++)
    {
        printf("Input the %s number: ", L[i]);
        scanf("%d", &n);

        if (n > 0)
        {
            C = C + n;
            P++;
        }
    }

    A = C / P;
    printf("\nNumber of positive numbers: %i\n", P);
    printf("Average value of the said positive numbers: %.2f\n", A);
}