#include "main.h"

void **_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char **A;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		A = malloc(new_size);
		if (A == NULL)
			return (NULL);
		free(ptr);
		return (A);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	A = malloc(new_size);
	if (A == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		A[i] = _strdup(ptr);
	free(ptr);
	return (*A);
}
