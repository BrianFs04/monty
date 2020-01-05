#include "monty.h"
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
