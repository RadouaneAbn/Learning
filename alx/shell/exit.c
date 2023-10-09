#include "main.h"

/**
 * check_exit - exits the shell
 * @s: the line to check if it contains "exit"
 * @exit_code: the exit status
 * @prg: the name of the program
 * @ncmd: the count of successive cmds executed
 *      in the program
 * Return: EXIT_SUCCESS or -1
 */

int check_exit(char *s, int *exit_code, char *prg, unsigned int ncmd)
{
	int T = 0, i = 0, /*j = 0*/ntmp = 0, sg = 0;
	char *e = "exit", tmp[16], err_msg[256];
/*
	while (s[i] == ' ')
		i++;
*/
	for (; s[i] && i < 4; i++)
	{
		if (s[i] != e[i])
			return (0);
	}

	while (s[i] == ' ')
		i++;
	if (s[i] == '\n' || s[i] == '\0')
		return (-1);
	if (s[i] == '-')
	{
		tmp[ntmp] = '-';
		ntmp++, i++;
	}
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			tmp[ntmp] = s[i];
			ntmp++;

		}
		else if (s[i] == '\n' || s[i] == '\0')
		{
			tmp[ntmp] = '\0';
			T = _atoi(tmp);
			if ((T >= 0 && T <= 2147483647) && sg == 0)
				*exit_code = T;
			else
			{
				error_ret(err_msg, prg, ncmd, e, tmp);
				write(STDERR_FILENO, err_msg, _strlen(err_msg));
				return (*exit_code = 2);
			}
		}
		else
		{
			sg = 1;
			tmp[ntmp] = s[i];
			ntmp++;
		}
		i++;
	}
	return (-1);
}

