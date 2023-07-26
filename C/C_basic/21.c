#include <stdio.h>

int main()
{
    int n;
    printf("Input an integer: ");
    scanf("%d", &n);

    if (0 <= n && n <= 20)
    {
        printf("Range [0, 20]\n");
    }

    else if (21 <= n && n <= 40)
    {
        printf("Range [21, 40]\n");
    }

    else if (41 <= n && n <= 60)
    {
        printf("Range [41, 60]\n");
    }
    
    else if (61 <= n && n <= 80)
    {
        printf("Range [61, 80]\n");
    }

    else{
        printf("Outside the range\n");
    }
}