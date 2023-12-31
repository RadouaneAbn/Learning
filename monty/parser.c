#include "monty.h"

void tokeniz(char *L, char **toks, char *d)
{
	char *tmp;
	int i = 0;

	tmp = strtok(L, d);
	for (i = 0; tmp && i < 2; i++)
	{
		toks[i] = strdup(tmp);
		tmp = strtok(NULL, d);
	}
}