#include <stdio.h>

int main()
{
    int c;
    printf("Input nuber of lines: ");
    scanf("%i", &c);

    if (c < 1)
    {
        printf("Invalid input,MUST be greater than 0\n");
    }

    for (int i = 1; i <= c; i++)
    {
        printf("%i %i %i\n", i, i*i, i*i*i);
    }

}