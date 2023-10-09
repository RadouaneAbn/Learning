#include "main.h"

void white_check(char *s)
{
	int i = 0, j = 0;

	if (s == NULL)
		return;

	while (s[i] == ' ')
		i++;

	for (; s[i]; i++)
	{
		if (s[i] != ' ')
		{
			if (s[i - 1] != ' ' || s[i + 1] != ' ')
				s[j++] = s[i];
		}
	}
	s[j] = '\0';
}
