#include "main.h"

char *_getenv(char *s, char **env)
{
	size_t sl = strlen(s);
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
/*
char **_getPATH(char *str, char **env)
{
    int i = 0, count;
    char *P, *tmp;
    char **path;

    P = _getenv(str, env);

    if (P == NULL)
        return (NULL);
    tmp = _strdup(P);

    tmp = _strtok(tmp, ":");
	for (count = 1; tmp; count++)
        tmp = _strtok(NULL, ":");
    free (tmp);
    path = malloc(count * sizeof(char *));
    if (path == NULL)
        return NULL;

    tmp = _strtok(P, ":");
   	for (; tmp; i++)
    {
        path[i] = _strdup(tmp);
		tmp = _strtok(NULL, ":");
    }
    path[i] = NULL;
    return (path);
}
*/