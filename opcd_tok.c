#include "monty.h"
glova_t glop;
/**
 * is_num - checks if it's a num
 * @n: received character
 * Return: 1 if success, 0 if it does not
 */
int is_num(char *n)
{
	int i = 0;

	if (n[i] == '-')
	{
		i++;
		if (n[i] == '\0')
			return (0);
	}
	for (; n[i]; i++)
	{
		if (isdigit(n[i]) == 0)
			return (0);
	}
	return (1);
}

/**
 * _strtok - tokenize input
 * @str: received characters
 * @stack: pointer to the stack
 * @line_number: line number
 */
void _strtok(char *str, stack_t **stack, unsigned int line_number)
{
	char *tk, *toky;

	tk = strtok(str, " ");
	if (tk == NULL)
		return;
	if (strcmp(tk, "push") == 0)
	{
		toky = tk;
		tk = strtok(NULL, " ");
		if (!is_num(tk))
		{
			printf("L%d: usage: push integer\n", line_number);
			free_dlistint(*stack);
			exit(EXIT_FAILURE);
		}
		glop.num = atoi(tk);
		selector(toky, stack, line_number);
	}
	else
		selector(tk, stack, line_number);
}
