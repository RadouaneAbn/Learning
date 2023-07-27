#include <stdio.h>

int main()
{
    float T = 0, A = 1, M = 1;
    
    for (int i = 0; i <= 3; i++)
    {
        T = T + A / M;
        A = A + 2;
        M = M * 2;
    }

    printf("Value of series: %.2f\n", T);
}