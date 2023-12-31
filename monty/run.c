#include "monty.h"

void run(char *cmd, stack_t **stack)
{
    char *buf[2];
    int i;
    instruction_t data[] = {
        {"queue", _queue},
        {"stack", _stack},
		{"push", _push},
		/*{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr}*/
	};

    tokeniz(cmd, input->token, " \n");
    if (!input->token)
		return;
    
    if (is_comment(input->token[0]))
		return;

    for (i = 0; i < 14; i++)
	{
		if (strcmp(input->token[0], data[i].opcode) == 0)
		{
			
		}
    }
    if (i == 14)
		
}