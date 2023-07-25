#include <stdio.h>

int main()
{
    double w1, w2, n1, n2, average;
    printf("Weith - Item 1 : ");
    scanf("%lf", &w1);
    printf("No. of item 1 : ");
    scanf("%lf", &n1);
    printf("Weith - Item 2 : ");
    scanf("%lf", &w2);
    printf("No. of item 2 : ");
    scanf("%lf", &n2);
    

    average = (w1 * n1 + w2 * n2) / (n1 + n2);
    printf("Average Value = %lf\n", average);
}