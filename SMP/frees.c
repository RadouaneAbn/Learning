#include "main.h"
#include <stdarg.h>

void free_functions(void);
/**
 * free_char1 - frees multple arguments of char *
 * @n: number of arguments
 */
void free_char1(const unsigned int n, ...)
{
	va_list all;
	unsigned int i;

	if (n == 0)
		return;

	va_start(all, n);

	for (i = 0; i < n; i++)
	{
		free(va_arg(all, char *));
	}

	va_end(all);
}

/**
 * free_list - frees a list
 * @head: the list
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
		free(tmp->path);
		free(tmp);
	}

	*head = NULL;
}

/**
 * free_grid - frees a 2 dimensional grid
 *	previously allocated by alloc_grid
 * @grid: the grid
 */

void free_grid(char **grid)
{
	int i = 0;

	for (i = 0; grid[i] ; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

/**
 * free_grid_half - frees the inside of a 2D Arr
 * @grid: the array to free
 */

void free_grid_half(char **grid)
{
	int i = 0;

	for (i = 0; grid[i] ; i++)
	{
		free(grid[i]);
	}
}

/**
 * free_m1 - frees multiple variables
 * @PATH: 1
 * @env: 2
 * @_line: 3
 * @line: 4
 */
void free_m1(list_t *PATH, New_env *env, char *_line, char *line)
{
	free_list(&PATH);
	free_grid(env->env_var);
	free_char1(3, _line, line, env);
}

/**
 * free_m2 - frees multiple variables
 * @PATH: 1
 * @env: 2
 * @_line: 3
 * @line: 4
 * @cmd: 5
 */
void free_m2(list_t *PATH, New_env *env, char *_line, char *line, char *cmd)
{
	free_list(&PATH);
	free_grid(env->env_var);
	free_char1(4, _line, line, env, cmd);
}

/**
 * free_m3 - frees multiple variables
 * @PATH: 1
 * @env: 2
 * @line: 3
 */
void free_m3(list_t *PATH, New_env *env, char *line)
{
	free_list(&PATH);
	free_grid(env->env_var);
	free_char1(2, line, env);
}
