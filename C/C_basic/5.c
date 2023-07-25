#include <stdio.h>

int height, width;
int perimeter, area;
int main()
{
    height = 7;
    width  = 5;

    perimeter = 2 * (height + width);
    area = height * width;

    printf("Perimeter of the rectangle = %i inche.\n", perimeter);
    printf("Area of the rectangle      = %i square inches\n", area);
}