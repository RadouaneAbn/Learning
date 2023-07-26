#include <stdio.h>

int main()
{
    int x, y;
    printf("Input the first number:  ");
    scanf("%i", &x);
    printf("Input the second number: ");
    scanf("%i", &y);

    if (x < y)
    {
        int temp;
        temp = y;
        y = x;
        x = temp;
    }

    if ((x % y) == 0)
    {
        printf("Multiplied!\n");
    }
    else
    {
        printf("not multiplied!!\n");
    }
}