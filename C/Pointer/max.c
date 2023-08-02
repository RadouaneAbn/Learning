#include <stdio.h>

void maximum(int *x, int *y, int *m)
{
    if (*x > *y)
    {
        *m = *x;
    }
    else
    {
        *m = *y;
    }
}

int main()
{
    int a, b, max;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Input b: ");
    scanf("%d", &b);
    maximum(&a, &b, &max);
    printf("Max: %d\n", max);
    return 0;
}