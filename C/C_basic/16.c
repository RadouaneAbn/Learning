#include <stdio.h>

int main()
{
    int A;
    float R[7] = {100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00};
    printf("Input the amount: ");
    scanf("%i", &A);

    for (int i = 0; i < 7; i++)
    {
        int t = 0;
        while (A >= R[i])
        {
            t++;
            A -= R[i];
        }
        printf("%i Note(s) of %.2f\n", t, R[i]);
    }
}
