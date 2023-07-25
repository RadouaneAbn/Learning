#include <stdio.h>

int main()
{   
    char id[10];
    long int hr, slin;
    float slout;
    printf("Input the Employees ID(MAX. 10 chars): ");
    scanf("%s", &id);
    printf("Input the working hrs: ");
    scanf("%ld", &hr);
    printf("Salary amount/hrs: ");
    scanf("%ld", &slin);

    slout = slin * hr;
    printf("Employees ID = %s\nSalary = U$ %.2f\n", id, slout);
}