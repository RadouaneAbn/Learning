#include "main.h"

/**
 * inter_mode - interactive mode
 */

void inter_mode(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 3);
		fflush(stdout);
	}
}

/**
 * int_to_str - this function coverts a integer to string
 * @n: the number that will converted
 * Return: return the result
 */

char *int_to_str(int n)
{
	int tmp = n, i;
	char *str;

	if (tmp == 0)
		return ("0");

	for (i = 0; tmp; i++)
		tmp /= 10;

	str = malloc(i + 1);
	str[i] = '\0';
	i--;

	tmp = n;
	for (; tmp; i--)
	{
		str[i] = tmp % 10 + '0';
		tmp /= 10;
	}

	return (str);
}
