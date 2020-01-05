#include "monty.h"
glova_t glop;
/**
 * free_dlistint - function that frees a doubly linked list
 * @head: Pointer to the first node of the list
 */
void free_dlistint(stack_t *head)
{
	if (head != NULL)
	{
		free_dlistint(head->next);
		free(head);
	}
}

/**
 * free_glop - frees and close global variable
 */
void free_glop(void)
{
	free_dlistint(glop.head);
	free(glop.buff);
	fclose(glop.fd);
}
