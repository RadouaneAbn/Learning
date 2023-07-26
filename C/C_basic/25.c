#include <stdio.h>

int main()
{
    int N;
    char* M[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Input a number (1 - 12) to get the month name: ");
    scanf("%d", &N);

    if (N > 0 && N < 12)
    {
        printf("The month is %s.\n", M[N - 1]);
    }
}