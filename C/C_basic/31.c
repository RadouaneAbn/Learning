#include <stdio.h>

int main()
{
    int I;
    printf("Input an integer: ");
    scanf("%i", &I);

    if ( I == 0)
    {
        printf("Even.\n");
    }
    if ( I > 0)
    {
        if ((I % 2) == 0 )
        {
            printf("Positive Even\n");
        }
        else
        {
            printf("Positive Odd.\n");
        }
    }
    if ( I < 0)
    {
      if ((I % 2) == 0 )
        {
            printf("Negative Even.\n");
        }
        else
        {
            printf("Negative Odd.\n");
        }  
    }
}