#include "monty.h"

int is_comment(char *line)
{
	/* check for comment*/
	if (line[0] == '#')
		return (1); /* if the line is a comment */

	return (0);	/* if not */
}