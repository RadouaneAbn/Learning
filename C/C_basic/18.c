#include <stdio.h>

int main()
{
    int D, M, Y;
    printf("Input No. of days: ");
    scanf("%i", &D);

    Y = D / 365;
    D = D - Y * 365;
    M = D / 30;
    D = D - M * 30;

    printf("%i Year(s)\n%i Month(s)\n%i Day(s)\n", Y, M, D);
}