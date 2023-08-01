#include <stdio.h>

int main()
{
    int d;
    printf("Input an integer: ");
    scanf("%i", &d);

    for ( int i = 1; i <= 100; i++ )
    {
        if ( (i % d) == 3)
        {
            printf("%i\n", i);
        }
    }
}