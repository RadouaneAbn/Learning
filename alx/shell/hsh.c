#include "main.h"

void t(void);
/**
 * main - Starts a shell
 * @ac: argument count
 * @av: argument variable
 * Return: EXIT_SUCCESS
 */

int main(int ac, char *av[], char **env)
{
	unsigned int ncmd = 0;
	char **tokens;
	int pid, k = 0;
	char *line = NULL, exec_err[256];
	char *path = _getenv("PATH", env);
	size_t len_line = 0;
	ssize_t read;
	int status, exit_code = 0, exit_read = 0;
	struct stat st;
	char *cmd;
	list_t *head = NULL;

	start_check(ac);
	pathTolist(&head, path);

	if (isatty(STDIN_FILENO))
	{
		printf("$ ");
		fflush(stdout);
	}
	while ((read = getline(&line, &len_line, stdin)) != -1)
	{
		exit_read = 0, k = 0, ncmd++;
	
		exit_read = check_exit(line, &exit_code, av[0], ncmd);	
		line[_strcspn(line, "\n")] = '\0';
		tokens = line_tokenizing(line, " \n");
		cmd = _strdup(tokens[0]);

		if (exit_read == -1)
		{
			free(path);
			free(line);
			exit(exit_code);
		}
		if (exit_read == 2 && !isatty(STDIN_FILENO))
		{
			free(path);
			free(line);
			exit(exit_read);
		}

		pid = fork();

		if (exit_read == 2 && pid == 0)
			return (2);

		while (line[k] == ' ')
			k++;



		if (pid == -1)
			printf("Yametee kodasaaai Red-Chan!!\n"), exit(98);

		if (pid == 0)
		{
			if (line[k] == '\0')
			{
				free(cmd);
				free(tokens);
				free_list(&head);
				free(line);
				exit(1);
			}

			/*
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
			*/
			if (execve(cmd, tokens, environ) == -1)
			{
				
				if (stat(tokens[0], &st) == -1 )
				{
					error_exec(exec_err, av[0], ncmd, tokens[0]);
					write(STDERR_FILENO, exec_err, _strlen(exec_err));
					exit(127);
				}
				else
				{
					perror("execve"), exit(2);
				}
			}
		}
		else
		{
			wait(&status);
	/*	if (exit_read != 2) */
			exit_code = status >> 8;
		}
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}
	}


	free(tokens);
	free_list(&head);
	free(line);
	free(cmd);
	return (0);

}
