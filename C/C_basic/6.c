#include <stdio.h>

double radius, area, perimeter;
float PI = 3.14;


int main()
{
    printf("Radius: \n");
    scanf("%le", &radius);

    perimeter = 2 * PI * radius;
    area = PI * radius * radius;

    printf("Perimeter of the Circle = %f inches\n", perimeter);
    printf("Area of the Circle      = %f square inches\n", area);
}