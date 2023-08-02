#include <stdio.h>

int main()
{
    int A[] = {12, 23, 34, 45, 56, 67, 78, 89, 90};
    int *P;
    P = A;

    for (int i = 0; i < 9; i++)
    {
        printf("%p \n", &A[i]);
        printf("--------------\n");
        printf("%p \n", ++P);
        printf("%d \n", *(P+3));
        printf("%ld \n", P - &A[4]);
        printf("%p \n", --P);
        printf("%p \n", A + 6);
        printf("%d \n", *(P + *(P + 8) - A[7]));
        printf("%d \n", P == &A[4]);
        printf("%d \n", P >= A);
        
    return 0;
    }
}