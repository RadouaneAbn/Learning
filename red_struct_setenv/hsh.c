#include "main.h"

void t(void);
/**
 * main - Starts a shell
 * @ac: argument count
 * @av: argument variable
 * @env: the enviremontal variable
 * Return: EXIT_SUCCESS
 */

int main(int ac, char *av[]/*, char **env*/)
{

	unsigned int ncmd = 0;
	char **tokens = NULL, *No_more_leak, *built_buff[1024];
	int i, pid, status, exit_code = 0, exit_read = 0;
	char *line = NULL, exec_err[256], *cmd, *_line, *path, startpwd[126];
	size_t len_line = 0;
	ssize_t read;
	list_t *head = NULL;


	Env *env = create_env(environ);
	/*   if (env_ptr->env == NULL)
	     {
	     env_ptr->env = cp_env(environ);
	     }*/


	path = _getenv("PATH", env->env);

	start_check(ac);
	PathToList(&head, path);
	_set_env("OLDPWD", getcwd(startpwd, 126), 0, env);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
	/* todo : while 1 / read = getline next_line */
	while ((read = _getline(&line, &len_line, stdin)) != -1)
	{
		_line = _liner(line);


		exit_read = 0;
		ncmd++;

		exit_read = check_exit(_line, &exit_code, av[0], ncmd);
		if (exit_read == -1)
		{
			/*free(_line);*/
			free_list(&head);
			/*free(line);*/
			for (i = 0; env->env[i] != NULL; i++)
			{
				free(env->env[i]);
			}
			free(env->env);
			/*free(env);*/
			free_char1(3, _line, line, env);
			exit(exit_code);
		}
		if (exit_read == 2 && !isatty(STDIN_FILENO))
		{
			/*free(_line);*/
			free_list(&head);

			/*free(line);*/
			for (i = 0; env->env[i] != NULL; i++)
			{
				free(env->env[i]);
			}
			free(env->env);
			/*free(env);*/
			free_char1(3, _line, line, env);
			exit(2);
		}

		/* if the command is builtin execute it*/
		if (_built(line))
		{
			No_more_leak = _strtok(_line, " ");
			for (i = 0; No_more_leak; i++)
			{
				built_buff[i] = _strdup(No_more_leak);
				No_more_leak = _strtok(NULL, " ");
			}
			built_buff[i] = NULL;

			_exec_built(built_buff, &exit_code, ncmd, av[0], env);
			if (isatty(STDIN_FILENO))
			{
				printf("$ ");
				fflush(stdout);
			}
			free(_line);


			for (i = 0; built_buff[i] != NULL; i++)
			{
				free(built_buff[i]);
			}
		}

		/* if it's not builtin, tokenize line */
		else if (exit_read == 0)
		{
			cmd = get_cmd(head, _line, &exit_code, exec_err, av[0], ncmd);
			if (cmd != NULL && cmd[0] != '\0' && exit_read == 0)
			{
				pid = fork();

				if (exit_read == 2 && pid == 0)
					return (2);

				if (pid == -1)
				{
					printf("Yametee kodasaaai Red-Chan!!\n");
					exit(98);
				}

				if (pid == 0)
				{

					tokens = line_tokens(_line, " ");

					if (execve(cmd, tokens, env->env) == -1)
					{
						perror("execve");
						_exit(2);
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
			{
				/*free(line);
				  free(_line);*/
				for (i = 0; env->env[i] != NULL; i++)
				{
					free(env->env[i]);
				}
				free(env->env);
				/*free(env);*/
				free_list(&head);
				/*free(cmd);*/
				free_char1(4, _line, line, env, cmd);
				return (exit_code);
			}
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 3);
				fflush(stdout);
			}
			if (cmd != NULL)
			{
				free(cmd);
				cmd = NULL;
			}
			free(_line);
		}

	}
	printf("got here\n");

	for (i = 0; env->env[i] != NULL; i++)
	{
		free(env->env[i]);
	}
	free(env->env);
	/*free(env);*/
	free_list(&head);
	/*free(line);*/
	free_char1(2, line, env);
	return (0);

}



