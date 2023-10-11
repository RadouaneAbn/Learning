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
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: the result of the compareson
 */

int _strcmp(char *s1, char *s2)
{
	int i, j, max;
	char *s3;

	if (_strlen(s1) <= _strlen(s2))
	{
		max = _strlen(s1);
		s3 = s1;
	}
	else
	{
		max = _strlen(s2);
		s3 = s2;
	}
	for (i = 0; i <= max && s3[i] != '\0'; i++)
	{
		j = s1[i] - s2[i];

		if (j != 0)
			break;
	}
	return (j);
}
