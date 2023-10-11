#include "main.h"

#include "main.h"

void t(void);
/**
 * main - Starts a shell
 * @ac: argument count
 * @av: argument variable
 * @env: the enviremontal variable
 * Return: EXIT_SUCCESS
 */

int main(int ac, char *av[], char **env)
{
    unsigned int ncmd = 0;
    char **tokens = NULL, **p_envtk;
    int /*i, */pid/*, count*/;
    char *line = NULL,/* *A, *tmp, */exec_err[256], *cmd, *p_env;
    size_t len_line = 0;
    ssize_t read;
    int status, exit_code = 0, exit_read = 0;
    char *path = _getenv("PATH", env), *_line;
    list_t *head = NULL;

    start_check(ac);
    PathToList(&head, path);

    if (isatty(STDIN_FILENO))
    {
        printf("$ ");
        fflush(stdout);
    }
    while ((read = _getline(&line, &len_line, stdin)) != -1)
    {
        /*printf("{{%ld}{%lu}}", read, len_line);*/
        _line = _liner(line);

        exit_read = 0;
        ncmd++;
        exit_read = check_exit(_line, &exit_code, av[0], ncmd);
        if (exit_read == -1)
        {
            free(_line);
            free_list(&head);
            free(line);
            exit(exit_code);
        }
        if (exit_read == 2 && !isatty(STDIN_FILENO))
        {
            free(_line);
            free_list(&head);
            free(line);
            exit(2);
        }

        
            if ((_strcmp(_line, "env") == 0) && !isatty(STDIN_FILENO))
            {
                _printenv();
                exit(0);
            }
            else if (isatty(STDIN_FILENO))
                cmd = get_cmd(head, _line, &exit_code, exec_err, av[0], ncmd);
        

        if (cmd != NULL && cmd[0] != '\0' && exit_read == 0)
        {
            /*if (stat(cmd, &st) == -1)
              {
              error_exec(exec_err, av[0], ncmd, cmd);
              write(STDERR_FILENO, exec_err, _strlen(exec_err));
              }              else*/
            pid = fork();


            if (exit_read == 2 && pid == 0)
                return (2);

            if (pid == -1)
                printf("Yametee kodasaaai Red-Chan!!\n"), exit(98);

            if (pid == 0)
            {
                tokens = line_tokens(_line, " ");
                /*tmp = _strdup(line);
                 *
                 *tmp = _strtok(tmp, " ");
                 *for (count = 1; tmp; count++)
                 *    tmp = _strtok(NULL, " ");
                 *
                 *tokens = malloc(count * sizeof(char *));
                 *if (tokens == NULL)
                 *    perror("tokens malloc"), exit(1);
                 *
                 *A = _strtok(line, " ");
                 *for (i = 0; A; i++)
                 *{
                 *    tokens[i] = _strdup(A);
                 *    A = _strtok(NULL, " ");
                 *}
                 *tokens[i] = NULL;
                 */

                /* env start
                 * if (_strcmp(tokens[0], "env") == 0)
                 *    execve("/usr/bin/printenv", tokens, env);
                 *
                 * env end
                 *else
                 */
                
                if ((execve(cmd, tokens, env) == -1) && !p_envtk[0])  /* changed if to else to check env */
                {
                    /*if (stat(cmd, &st) == -1)
                      {
                      error_exec(exec_err, av[0], ncmd, tokens[0]);
                      write(STDERR_FILENO, exec_err, _strlen(exec_err));
                      exit(2);
                      }
                      else*/
                    perror("execve"), _exit(2);
                }
            }
            else
            {
                wait(&status);
                if (exit_read != 2)
                    exit_code = status >> 8;
            }

        }
        else if (!isatty(STDIN_FILENO) && exit_code != 0)
        {            free(line);
            free(_line);
            free_list(&head);
            return (exit_code);
        }
        if (isatty(STDIN_FILENO))
        {
            printf("$ ");
            fflush(stdout);
        }
        free(cmd);
        free(_line);
    }

    free_list(&head);
    free(line);
    return (0);

}
