#include <unistd.h>

/**
 * _puts - this function will print a string
 * @str: pointer to the string
 * Return: always return void
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
	write(1, "\n", 1);
}
