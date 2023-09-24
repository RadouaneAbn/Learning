#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

size_t print_list(const list_t *h)
{
	const list_t *current = h;
	size_t number_of_nodes = 0;

	while (current != NULL)
	{
		if (current->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", current->len, current->str);
		current = current->next;
		number_of_nodes++;
	}

	return (number_of_nodes);
}
