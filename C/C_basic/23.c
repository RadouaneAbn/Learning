#include <stdio.h>

int main()
{
    float n[3], X = 0;
    char* L[3] = {"first", "second", "third"};
    
    for (int i = 0; i < 3; i++)
    {
        printf("Input the %s number: ", L[i]);
        scanf("%f", &n[i]);
    }

    if (n[0] < (n[1] + n[2]) && n[1] < (n[0] + n[2]) && n[2] < (n[0] + n[1]))
    {
        X = n[0] + n[1] + n[2];
        printf("Perimeter = %.1f\n", X);
    }
    else
    {
        printf("Not possible to create a triangle..!\n");
    }
}