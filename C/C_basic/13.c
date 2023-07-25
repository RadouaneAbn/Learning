#include <stdio.h>

int main()
{
    long int m = 0;
    long int n[3];
    int i;
    printf("Input the first integer: ");
    scanf("%ld", &n[0]);
    printf("Input the second integer: ");
    scanf("%ld", &n[1]);
    printf("Input the third integer: ");
    scanf("%ld", &n[2]);

    for (i = 0;  i < 3; i++)
    {
        if (n[i] > m)
        {
            m = n[i];
        }
    }

    printf("Maximum value of three integers : %ld\n", m);
}