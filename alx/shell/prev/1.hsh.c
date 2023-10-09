#include "main.h"

/**
 * main - Starts a shell
 * Return: EXIT_SUCCESS
 */

int main(void)
{
	char *envp[] = {"PATH=/usr/bin:/bin", NULL}, **tokens;
	int i, pid, count;
	char *line = NULL, *A, *tmp;
	size_t len_line = 0;
	ssize_t read;

	printf("$ ");
	while ((read = getline(&line, &len_line, stdin)) != -1)
	{
		if (check_exit(line) == -1)
			exit(1);

		pid = fork();

		line[_strcspn(line, "\n")] = '\0';
		if (pid == -1)
			printf("Yametee kodasaaai Red-Chan!!\n"), exit(98);

		if (pid == 0)
		{
			line[_strcspn(line, "\n")] = '\0';
			if (line[0] == '\0')
				exit(1);

			tmp = _strdup(line);
			/*	if (tmp = NULL)
				perror("tmp dup"), exit(1); */
			tmp = strtok(tmp, " ");
			for (count = 1; tmp; count++)
				tmp = strtok(NULL, " ");

			tokens = malloc(count * sizeof(char *));
			if (tokens == NULL)
				perror("tokens malloc"), exit(1);

			A = strtok(line, " ");
			for (i = 0; A; i++)
			{
				tokens[i] = _strdup(A);
				A = strtok(NULL, " ");
			}
			tokens[i] = NULL;

			if (execve(tokens[0], tokens, envp) == -1)
				perror("execve"), exit(1);
		}
		else
			wait(NULL);

		printf("$ ");
	}

	/*free(line);
	  for (i = 0; i < count; i++)
	  free(tokens[i]);
	  free(tokens);*/
	return (0);

}
