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
		else if (str[i] != '\n' && str[i] != '#')
			BUF[k++] = str[i++];

		for (; str[i] && str[i] != '\n'; i++)
		{
			/* breaks the loop if the first char is #*/
			if (str[i] == '#' && i == 0)
				break;

			/* breaks the loop if ' #' is found*/
			if (str[i] == '#' && str[i - 1] == ' ')
				break;

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

	return (_strdup(BUF));
}
