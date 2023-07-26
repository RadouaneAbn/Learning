#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    long int dis;
    float ful;
    printf("Input total distance in km: ");
    scanf("%ld", &dis);
    printf("Input total fuel spent in liters: ");
    scanf("%f", &ful);

    float con = dis / ful;

    printf("Average consumption (km/lt) %.3f\n", con);
}