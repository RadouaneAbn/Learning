#include <stdio.h>

int main()
{
    float T = 0;
    for (int i = 1; i <= 50; i++)
    {
        T = T + 1 / (float)i;
    }

    printf("Value of series: %.2f\n", T);
}