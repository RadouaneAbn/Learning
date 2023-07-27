#include <stdio.h>

int main()
{
    int a1, a2, a3, a4, a5;
    int sum = 0;

    printf("Input the first number:  ");
    scanf("%d", &a1);
    printf("Input the second number: ");
    scanf("%d", &a2);
    printf("Input the third number:  ");
    scanf("%d", &a3);
    printf("Input the fourth number: ");
    scanf("%d", &a4);
    printf("Input the fifth number:  ");
    scanf("%d", &a5);

    if ((a1 % 2) != 0)
    {
        sum = sum + a1;
    }
    if ((a2 % 2) != 0)
    {
        sum = sum + a2;
    }
    if ((a3 % 2) != 0)
    {
        sum = sum + a3;
    }
    if ((a4 % 2) != 0)
    {
        sum = sum + a4;
    }
    if ((a5 % 2) != 0)
    {
        sum = sum + a5;
    }

    printf("Sum of all odd values: %d\n", sum);
}