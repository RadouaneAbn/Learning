#include "main.h"

void error_ret(char *err_msg, char *prg,unsigned int ncmd,
	char *cmd, char *tmp)
{
	unsigned int l = 0, n = ncmd;
	char num[20], *delim = ": ", *err1 = ": Illegal number: ";

	while (n != 0)
	{
		num[l] = n % 10 + '0';
		n /= 10, l++;
	}
	num[l] = '\0';

	l = 0;
	_strcpy(err_msg, prg);
	_strcat(err_msg, delim);
	_strcat(err_msg, num);
	_strcat(err_msg, delim);
	_strcat(err_msg, cmd);
	_strcat(err_msg, err1);
	_strcat(err_msg, tmp);
	_strcat (err_msg, "\n");

}

/**
 * check_exit - exits the shell
 * @s: the line to check if it contains "exit"
 * Return: EXIT_SUCCESS or -1
 */

int check_exit(char *s,int *exit_code, char *prg, unsigned int ncmd)
{
	int T = 0;
	int i = 0, ntmp = 0, sg = 0;
	char *e = "exit", tmp[16], err_msg[256];

	for (; s[i] && i < 4; i++)
	{
		if (s[i] != e[i])
			return (0);
	}

	while (s[i] == ' ')
		i++;

	if (s[i] == '\n' || s[i] == '\0')
		return (-1);
	else
	{
		if (s[i] == '-')
		{
			tmp[ntmp] = '-';
			sg = -1;
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
				T = atoi(tmp) ;
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
	}

	return (-1);
}

