#include "main.h"

void _printenv(void)
{
    extern char **environ;
    int i;

    printf("\n\n\newg\newg\n");
    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}