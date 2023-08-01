#include <stdio.h>

int main()
{
    int x, y;
    float D;
    printf("Input the Coordinate(x,y):\n");
    printf("x: ");
    scanf("%i", &x);
    printf("y: ");
    scanf("%i", &y);

    if (y != 0)
    {
        D = x / y;
        printf("%i / %i = %.1f\n",x, y, D);
    }
    else
    {
        printf("Division is not possible\n");
    }
}