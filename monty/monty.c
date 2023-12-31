#include "monty.h"

int main(int ac, char *av[])
{
    if (ac > 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    if (ac == 2)
        start(av[1]);

    return (0);
}