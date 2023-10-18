#include "main.h"

/**
 * 
 * 
 */

int _unset_env(char *var_name, Env *env)
{
    int i;

    if (var_name == NULL)
    {
        perror("unsetenv");
        return (-1);
    }

    for (i = 0; env->env[i]; i++)
    {
        if (_strncmp(env->env[i], var_name, _strlen(var_name)) == 0)
        {
            free(env->env[i]);
            for(; env->env[i]; i++)
            {
                env->env[i] = env->env[i + 1];
            }
            return (0);
        }
    }
    return (0);
}

int change_dir(char **token, char *prg, unsigned int ncmd, Env *env)
{
    char *dir, pwd[1024], oldpwd[1024];
    char err_msg[1024];
    int cd_ret;

    getcwd(oldpwd, 126);
		
		if (token[1] == NULL)
		{
			dir = _getenv("HOME", env->env);
			if (dir == NULL)
				return (0);
		}		

		else if (token[1][0] == '-')
		{
			dir = _getenv("OLDPWD", env->env);
			write(STDOUT_FILENO, dir, _strlen(dir));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			dir = token[1];

		
		cd_ret = chdir(dir);
		if (cd_ret == -1)
		{
			error_cd(err_msg, prg, ncmd, dir);
            write(STDERR_FILENO, err_msg, _strlen(err_msg));
			return (1);
		}
		else
		{
			_set_env("OLDPWD", oldpwd, 1, env);
			_set_env("PWD", getcwd(pwd, 126), 1, env);
			return (0);
        }
}