#include <stdio.h>

int main()
{
    int P;
    printf("Input the password: ");
    scanf("%i", &P);

    while (P != 1234)
    {
        printf("Incorrect password, try again: ");
        scanf("%i", &P);
    }
    
    printf("Correct password\n");

}