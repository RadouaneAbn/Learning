#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int i;
    char pass[16];
    char *CHARS = "7abc2defghi-jklmn!6o1pqrstu/8vwx%yzAB*4CDE9+FG&HIJK0LMNOP3$QRSTU-VWXYZ5";
    int L = strlen(CHARS);

    srand(time(NULL) * rand());

    for (i = 0; i < 16; i++)
        pass[i] = CHARS[rand() % L];

    printf("[ %s ]\n", pass);

    return (0);
}