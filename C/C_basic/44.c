#include <stdio.h>

int main()
{
    int n;
    float A, T = 0, x;
    printf("Input Mathematics marks (0 to terminate): \n");

while (scanf("%f", &x) == 1)
{
    if (x > 0)
    {
        T += x;
        n++;
    }
    else
    {
        break;
    }

}

A = T / n;
printf("Average marks in Mathematics: %.2f\n", A);
}