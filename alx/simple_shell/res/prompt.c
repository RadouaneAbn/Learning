#include "main.h"

int main(void)
{
	char *line = NULL, *A, *tokens[256];
	size_t len = 0;
	ssize_t read;
	int i = 0, start;

	printf("$ ");

	while ((read = getline(&line, &len, stdin)) != -1)
	{
		start = 0, i = 0;
		A = strtok(line, "\n");
		A = strtok(line, " ");
		while (A)
		{
			tokens[i] = A;
			A = strtok(NULL, " ");
			i++;
		}

		while (start < i)
			printf("%s\n", tokens[start++]);
		printf("$ ");
	}


	free(line);

	return (0);
}
