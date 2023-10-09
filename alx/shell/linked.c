#include "main.h"

/**
 * free_listint2 - this function frees a listint_t list
 * @head: the head of the list
 */

void free_list(list_t **head)
{
	list_t *tmp;

	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->p);
		free(tmp);
	}

	*head = NULL;
}

list_t *add_node_end(list_t **head, char *p)
{
	list_t *current, *new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);

	new->p = _strdup(p);
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

size_t pathTolist(list_t **head, char *path)
{
    char *tmp;

    if (path == NULL)
        return (2);

    tmp = _strtok(path, ":");
    while (tmp)
	{
		add_node_end(head, tmp);
		tmp = _strtok(NULL, ":");
	}

	free(tmp);
    return (0);
}

size_t print_list(const list_t *head)
{
	size_t number_of_nodes = 0;

	while (head != NULL)
	{
		printf("%s\n", head->p);
		head = head->next;
		number_of_nodes++;
	}

	return (number_of_nodes);
}