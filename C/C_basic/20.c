#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, x1, x2, X;
    printf("Input the first number(a):  ");
    scanf("%lf", &a);
    printf("Input the second number(b): ");
    scanf("%lf", &b);
    printf("Input the third number(c):  ");
    scanf("%lf", &c);

    X = pow(b, 2) - 4 * a * c;

    if (a != 0 && X > 0)
    {
        x1 = (-b + sqrt(X)) / (2 * a);
        x2 = (-b - sqrt(X)) / (2 * a);

        printf("Root1 = %.5lf\n", x1);
        printf("Root2 = %.5lf\n", x2);
    }
    else{
        printf("Impossible to find the roots.\n");
    }
}