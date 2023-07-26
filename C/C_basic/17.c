#include <stdio.h>

int main()
{
    
    int S, H, M;
    printf("Input seconds: ");
    scanf("%i", &S);

    H = S / 3600;           //Hours
    S = S - H * 3600;       
    M = S / 60;             //minutes
    S = S - M * 60;         //seconds

    printf("H:M:S - %d:%d:%d\n", H, M, S);

}