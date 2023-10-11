#include "main.h"

/**
 * _liner - removes whitespaces
 * @str: the str to handle
 * Return: the clean str
 */

char *_liner(char *str)
{
	char BUF[1024];
	int i = 0, k = 0;

	if (str != NULL)
	{
		if (str[i] == ' ')
			i++;
		else if (str[k] != '\n')
			BUF[k++] = str[i++];

		for (; str[i] && str[i] != '\n'; i++)
		{
			if (str[i] != ' ')
				BUF[k++] = str[i];
			else if (str[i] == ' ' && str[i - 1] != ' ')
				BUF[k++] = str[i];
		}
	}
	if (BUF[k - 1] == ' ')
		BUF[k - 1] = '\0';
	else
		BUF[k] = '\0';

	return (strdup(BUF));
}
