#include "main.h"

int _strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *_strdup(char *str)
{
	char *A;
	int i, sl;

	if (str == NULL)
		return (NULL);

	sl = _strlen(str);
	A = malloc(sl + 1);

	if (A == NULL)
		return (NULL);
	for (i = 0; i < sl; i++)
		A[i] = str[i];
	A[i] = '\0';
	return (A);
}

int check_exit(char *s)
{
	int i;
	char *exit = "exit\n";
	
	for (i = 0; s[i]; i++)
	{
		if (s[i] != exit[i])
			return (0);
	}
	return (-1);
}

int main(void)
{
	char *envp[] = {"PATH=/usr/bin:/bin", NULL}, **tokens;
	int i, pid, count, cmd_count = 1;
	char *line = NULL, *A, *tmp;
	size_t len_line = 0;
	ssize_t read;

		printf("==> ");
	while (cmd_count)
	{
		read = getline(&line, &len_line, stdin);
		if (read == -1)
			exit(1);

		if (check_exit(line) == -1)
			exit(1);
		pid = fork();

		line[strcspn(line, "\n")] = '\0';
		if (pid == -1)
			printf("Yametee kodasaaai Red-Chan!!\n"), exit(98);

		if (pid == 0)
		{
			if (line[0] == '\0')
				exit(1);

			tmp = _strdup(line);
			tmp = strtok(tmp, " ");
			for (count = 1; tmp; count++)
				tmp = strtok(NULL, " ");
			tokens = malloc(count * sizeof(char *));
			if (tokens == NULL)
				perror("Tmalloc"), exit(1);

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

	}
	return (0);

}
