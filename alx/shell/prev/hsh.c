#include "main.h"
unsigned int ncmd = 0;

void test(void);
/**
 * main - Starts a shell
 * Return: EXIT_SUCCESS
 */

int main(int ac, __attribute__ ((unused))char *av[])
{
	char **tokens;
	int i, pid, count, k = 0;
	char *line = NULL, *A, *tmp;
	size_t len_line = 0;
	ssize_t read;
	int status, exit_code = 0, exit_read = 0;

	start_check(ac);

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	while ((read = getline(&line, &len_line, stdin)) != -1)
	{
		exit_read = 0, k = 0, i = 0;
		ncmd++;

		exit_read = check_exit(line, &exit_code, av[0], ncmd);
		
		if (exit_read == -1)
		{
			free(line);
			exit(exit_code);
		}
		if (exit_read == 2 && !isatty(STDIN_FILENO))
		{
			free(line);
			exit(2);
		}
		pid = fork();

		if (exit_read == 2 && pid == 0)
			return (2);

		while (line[k] == ' ')
			k++;

		line[_strcspn(line, "\n")] = '\0';

		if (pid == -1)
			printf("Yametee kodasaaai Red-Chan!!\n"), exit(98);

		if (pid == 0)
		{
			if (line[k] == '\0')
			{
				free(line);
				exit(1);
			}
			tmp = _strdup(line);
			
			tmp = _strtok(tmp, " ");
			for (count = 1; tmp; count++)
				tmp = _strtok(NULL, " ");

			tokens = malloc(count * sizeof(char *));
			if (tokens == NULL)
				perror("tokens malloc"), exit(1);

			A = _strtok(line, " ");
			for (i = 0; A; i++)
			{
				tokens[i] = _strdup(A);
				A = _strtok(NULL, " ");
			}
			tokens[i] = NULL;

			if (execve(tokens[0], tokens, environ) == -1)
				perror("execve"), exit(2);
		}
		else
		{
        wait(&status);
		if (exit_read != 2)
    		exit_code = status >> 8;
    	}
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
	}

	free(line);
	return (0);

}
