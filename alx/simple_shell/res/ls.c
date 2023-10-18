#include "main.h"

int main(int __attribute__ ((unused)) ac, char **av)
{
	char *envp[] = {"PATH=/usr/bin:/bin", NULL};
	pid_t pid;
	int i;

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid > 0)
			wait(NULL);
		else if (pid == 0)
			if (execve(av[1], &av[1], envp) == -1)
				return (-1);
		else
			exit(98);
	}


	return (0);
}
