#include "main.h"

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *A;

	A = malloc(size * sizeof(char));
	if (A == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
		A[i] = c;
	return (A);
}
