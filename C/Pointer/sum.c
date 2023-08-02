#include <stdio.h>

int main()
{
    int T[6];
    int *P = T;
    printf("enter six valid numbers: \n");
    for (P = T; P < T + 6; P++)
    {
        printf("T[%d] = ", P - T);
        scanf("%d", P);
    }

    int sum = 0;
    for (P = T; P < T + 6; P++)
    {
        sum = sum + *P;
    }

    printf("The sum is %d\n", sum);
}