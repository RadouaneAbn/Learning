#include "main.h"

/**
 *
 */

int _built(char *token_0)
{
	char *possible[] = {"env", "setenv", "unsetenv", "cd", NULL};
	int i;


	for (i = 0; possible[i]; i++)
	{
		if (_strcmp(token_0, possible[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 *
 */

void _exec_built(char **token, int *exit_code, unsigned int ncmd, char *prg, Env *env)
{
	char *err_set = "An error has been occured\n";
	int tok3_sub = 1;

	if (_strcmp(token[0], "env") == 0)
	{
		_printenv(env);
	}

	else if (_strcmp(token[0], "setenv") == 0)
	{
		if (token[1] == NULL || token[2] == NULL)
		{
			write(STDERR_FILENO, err_set, _strlen(err_set));
			return;
		}
		else if ((token[3]) != NULL)
			tok3_sub = _atoi(token[3]);

		_set_env(token[1], token[2], tok3_sub, env);
	}
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		if (token[1] == NULL)
		{
			write(STDERR_FILENO, err_set, _strlen(err_set));
			return;
		}
		_unset_env(token[1], env);
	}
	else if (_strcmp(token[0], "cd") == 0)
	{
		*exit_code = change_dir(token, prg, ncmd, env);
	}
}


/**
 *
 */

/*void _printenv(char **tokens, int *exit_code, Env *env)
{
	int i;
	(void) tokens;

	for (i = 0; env->env[i]; i++)
	{
		write(STDOUT_FILENO, env->env[i], _strlen(env->env[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	*exit_code = 0;
}*/

/**
 *
 */
int _set_env(char *var_name, char *var_value, int condition, Env *env)
{
	char *new_var;
	int i;

	if (var_name == NULL || var_value == NULL || _strchr(var_name, '=') != NULL)
	{
		perror("setenv");
		return (-1);
	}

	new_var = malloc(_strlen(var_name) + _strlen(var_value) + 2);
	if (new_var == NULL)
	{
		free(new_var);
		perror("setenv");
		return (-1);
	}

	_strcpy(new_var, var_name);
	_strcat(new_var, "=");
	_strcat(new_var, var_value);

	for (i = 0; env->env[i]; i++)
	{
		if (_strncmp(env->env[i], var_name, _strlen(var_name)) == 0)
		{
			if (condition == 0)
			{
				free(new_var);
				return (0);
			}
			env->env[i] = new_var;
			return (0);
		}
	}

	env->env= realloc(env->env, sizeof(char *) * (i + 2));
	env->env[i + 1] = NULL;
	env->env[i] = new_var;
	return (0);
}

/**
 *
 */

Env *create_env(char **environ)
{
	Env *env = malloc(sizeof(Env));
	env->env = cp_env(environ);
	return (env);
}

/**
 *
 */

char **cp_env(char **environ)
{
	int i = 0;
	char **new_env = NULL;

	while (environ[i] != NULL)
	{
		i++;
	}

	new_env = malloc((i + 1) * sizeof(char *));

	for (i = 0; environ[i] != NULL; i++)
	{
		new_env[i] = _strdup(environ[i]);
	}

	new_env[i] = NULL;
	return (new_env);
}



void _printenv(Env *env)
{
    int env_size = 0, i;
    char **env_cpy = NULL;

    for (i = 0; env->env[i]; i++)
    {
        env_size += _strlen(env->env[i]) + 1;
    }
    env_cpy = malloc((env_size + 1) * sizeof(char));

    for (i = 0; env->env[i]; i++)
    {
    env_cpy[i] = (char *)malloc(_strlen(env->env[i]) + 1 * sizeof(char));
    _strcpy(env_cpy[i], env->env[i]);
    }
    env_cpy[i] = NULL;
    
    for (i = 0; env_cpy[i]; i++)
    {
        write(STDOUT_FILENO, env_cpy[i], _strlen(env_cpy[i]));
		write(STDOUT_FILENO, "\n", 1);
    }
    /*write(STDOUT_FILENO, \n");*/
     for (i = 0; env_cpy[i]; i++)
    {
        free(env_cpy[i]);
    }
    free(env_cpy);
}