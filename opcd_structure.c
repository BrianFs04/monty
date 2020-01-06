#define GLOB
#include "monty.h"

/**
 * selector - structure
 * @op_str: received string
 * @stack: pointer to stack
 * @line_number: line number
 */
void selector(char *op_str, stack_t **stack, unsigned int line_number)
{
	instruction_t sl[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{NULL, NULL}
	};

	int i = 0;

	while (sl[i].opcode != NULL)
	{
		if (strcmp(sl[i].opcode, op_str) == 0)
		{
			sl[i].f(stack, line_number);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, op_str);
	free_dlistint(*stack);
	fclose(glop.fd);
	exit(EXIT_FAILURE);
}
