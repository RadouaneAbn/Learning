#include "main.h"

void test(void);
/**
 * _strlen - return the length of a string
 * @s: the string
 * Return: the length
 */

int _strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

/**
 * _strcpy - copies a strings
 * @src: the string to copy
 * @dest: the destination
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

/**
 * _strdup - returns a pointer to a newly
 *    allocated space in memory, which contains
 *    a copy of the string given as a parameter
 * @str: the string
 * Return: Pointer
 */

char *_strdup(char *str)
{
    int len, i;
    char *s;

    if (str == NULL)
        return (NULL);

    len = _strlen(str);
    s = malloc(len + 1);

    if (s == NULL)
        return (NULL);
    for (i = 0; i < len; i++)
        s[i] = str[i];
    s[i] = '\0';
    return (s);

}
/**
 * main - Super Simple Shell 98
 * Return: 98
 */

int main(void)
{
    char *envp[] = {"PATH=/usr/bin:/bin", NULL}, **tokens;
    int i, count = 0, pid;
    char *line = NULL, *A, *cp_line;/*, *tmp_line*/
    size_t len_line = 0;
    ssize_t ret_get;

    printf("$ ");
    while ((ret_get = getline(&line, &len_line, stdin)) != -1)
    {
        line[strcspn(line, "\n")] = '\0';
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            printf("Yametee kodasaaai Red-Chan!!\n");
            exit(98);
        }

        if (pid == 0)
        {
            cp_line = _strdup(line);
            if (cp_line == NULL) {
                perror("cp_line dup");
                exit(1);
            }

            count = 0;
            A = strtok(cp_line, " ");
            while (A != NULL)
            {
                count++;
                A = strtok(NULL, " ");
            }

            tokens = malloc((count + 1) * sizeof(char *));
            if (tokens == NULL)
            {
                perror("Tokens malloc");
                exit(1);
            }

          /*  line = strtok(line, "\n");*/
            A = strtok(line, " ");
            for (i = 0; i < count; i++)
            {
                tokens[i] = _strdup(A);
        /*        _strcpy(tokens[i], A);
                printf("%s\n", tokens[i]); */
                A = strtok(NULL, " ");
            }
            tokens[count] = NULL;

            if (execve(tokens[0], tokens, envp) == -1)
            {
                perror("execve error");
                exit(1);
            }
        }
        else
            wait(NULL);

        printf("$ ");
    }

    free(line);
    free(cp_line);
    for (i = 0; i < count; i++)
        free(tokens[i]);
    free(tokens);
    return (0);

}
