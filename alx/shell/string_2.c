#include "main.h"

/**
 * _atoi - this function will convert a string to an integer
 * @s: the string
 * Return: the converted integer
 */

int _atoi(char *s)
{
	int i = 0, end = 0, sign = 1;
	unsigned int T = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		while (s[i] >= '0' && s[i] <= '9')
		{
			end = 1;
			T = T * 10 + s[i] - '0';
			i++;
		}
		if (end == 1)
			break;
		i++;
	}
	return (T * sign);
}

/**
 * strncmp - this function compares n bytes of two strings
 * @s1: the first string
 * @s2: the second string
 * Return: 0 if the if successed
 *	-1 if it failes
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (-1);
	}

	return (0);
}
