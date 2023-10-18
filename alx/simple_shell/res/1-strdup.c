#include "main.h"
#include <stdlib.h>

char *_strdup(char *str)
{
	char *A;
	int i, sl;

	if (str == NULL)
		return (NULL);

	sl = _strlen(str);
	A = malloc(sl + 1);

	if (A == NULL)
		return (NULL);
	for (i = 0; i < sl; i++)
		A[i] = str[i];
	A[i] = '\0';
	return (A);
}
