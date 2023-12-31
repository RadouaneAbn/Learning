#include "monty.h"

info_t *input;

void start(char *file_name)
{
    char *BUF = NULL;
    size_t len;
    stack_t *stack = NULL;

    input = malloc(sizeof(info_t));
    if (input == NULL)
    {
        fprintf(stderr, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    input->fd = fopen(file_name, "r");
    if (input->fd == NULL) /** fprint error */
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE); /*exit failure*/
	}

    input->mode = STACK;
    input->L = 0;
    while(getline(&BUF, &len, input->fd) != -1)
        run(BUF, &stack);
}