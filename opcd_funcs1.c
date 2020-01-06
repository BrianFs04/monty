#define GLOB
#include "monty.h"

/**
 * add - adds the two top elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int elem;
	stack_t *new, *tmp;

	new = *stack;

	while (new != NULL)
	{
		new = new->next;
		elem++;
	}

	if (elem < 2)
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n",
			line_number);
		free_glop();
		exit(EXIT_FAILURE);
	}
	new = (*stack)->next;
	new->n += (*stack)->n;
	new->prev = NULL;
	tmp = *stack;
	*stack = new;
	free(tmp);
}

/**
 * nop - no operation
 * @stack: pointer to the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
