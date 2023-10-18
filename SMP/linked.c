#include "main.h"


/**
 * print_list - prints a list
 * @h: the list
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t number_of_nodes = 0;

	while (h != NULL)
	{
		printf("%s\n", h->path);
		h = h->next;
		number_of_nodes++;
	}

	return (number_of_nodes);
}


/**
 * add_node_end - adds a node to the list
 * @head: the list
 * @p: the added node
 * Return: the new list
 */

list_t *add_node_end(list_t **head, const char *p)
{
	list_t *current,  *new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->path = strdup(p);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	current = *head;

	while (current->next != NULL)
		current = current->next;

	current->next = new;

	return (new);
}

/**
 * _getenv - extracts the enviromental variable
 * @s: the variable
 * @env: the global enviromental variable
 * Return: the variable's elements
 */

char *_getenv(char *s, char **env)
{
	size_t sl = _strlen(s);
	char **tmp = env;

	while (*tmp)
	{
		if (_strncmp(*tmp, s, sl) == 0 && (*tmp)[sl] == '=')
		{
			return (&(*tmp)[sl + 1]);
		}
		tmp++;
	}
	return (NULL);
}
