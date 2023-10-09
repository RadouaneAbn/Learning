#include "main.h"

/**
 * error_ret - generates an error message
 * @err_msg: the err's message string concatenated
 * @prg: the name of the program
 * @ncmd: the count of successive cmds executed
 *	in the program
 * @cmd: the executed command
 * @tmp: temporary string
 */

void error_ret(char *err_msg, char *prg, unsigned int ncmd,
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
	_strcat(err_msg, "\n");
}

/**
 * error_exec - generates an error message for
 *	execve function if the file is not found
 * @err_msg: the err's message string concatenated
 * @prg: the name of the program
 * @ncmd: the count of successive cmds executed
 *	in the program
 * @cmd: the executed command
 * @tmp: temporary string
 */

void error_exec(char *err_msg, char *prg, unsigned int ncmd,
		char *cmd)
{
	unsigned int l = 0, n = ncmd;
	char num[20], *delim = ": ", *err1 = ": not found";

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
	_strcat(err_msg, "\n");
}
