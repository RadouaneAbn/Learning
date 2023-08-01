#include <stdio.h>

int main()
{
    float x, y;
    printf("Input the Coordinate(x,y):\n");
    printf("x: ");
    scanf("%f", &x);
    printf("y: ");
    scanf("%f", &y);

    if (x >= 0 && y >= 0)
    {
        printf("Quadrant-I(+,+)\n");
    }

    if (x < 0 && y >= 0)
    {
        printf("Quadrant-II(-,+)\n");
    }

    if (x < 0 && y < 0)
    {
        printf("Quadrant-III(-,-)\n");
    }

    if (x >= 0 && y < 0)
    {
        printf("Quadrant-IV(+,-)\n");
    }
}