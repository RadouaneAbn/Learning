#include <stdio.h>

int main()
{
    int a, b;
    printf("Input the first integer: ");
    scanf("%i", &a);
    printf("Input the second integer: ");
    scanf("%i", &b);

    if(a > b) 
	{
        int tmp;
		tmp = b;
		b = a;
		a = tmp;
	}

    for (int i = a; i <= b; i++)
    {
        if ((i % 7) == 2 || (i % 7) == 3)
        {
            printf("%i\n", i);
        }
    }
}