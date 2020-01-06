#define GLOB
#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed");
		free_glop();
		exit(EXIT_FAILURE);
	}
	new->n = glop.num;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	new = *stack;

	while (new != NULL)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO,
			"L%u: can't pint, stack empty\n", line_number);
		free_dlistint(*stack);
		free_glop();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%d can't pop an empty stack\n",
		       line_number);
		free_dlistint(*stack);
		free_glop();
		exit(EXIT_FAILURE);
	}
	new = *stack;
	*stack = (*stack)->next;
	free(new);
}

/**
 * swap - swaps the top 2 elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			line_number);
		free_glop();
		exit(EXIT_FAILURE);
	}

	new = (*stack)->next;
	(*stack)->prev = new;
	(*stack)->next = new->next;
	new->prev = NULL;

	if (new->next)
		(new->next)->prev = *stack;
	new->next = *stack;
	*stack = new;
}
