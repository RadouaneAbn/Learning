#include "main.h"

int take_cmd(char *tokens[])
{
	char *envp[] = {"PATH=/usr/bin:/bin", NULL};

	if(execve(av[0], av, envp) == -1)
		return (-1);

	return (0);
}
