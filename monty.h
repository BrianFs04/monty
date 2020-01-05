#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glo_va - global structure
 * @num: value
 * @nline: line number
 * @head: pointer to stack's head
 * @buff: buffer
 * @fd: file descriptor
 * @size: size in bytes
 */
typedef struct glo_va
{
	int num;
	unsigned int nline;
	stack_t *head;
	char *buff;
	FILE *fd;
	size_t size;
} glova_t;

extern glova_t glop;

/* monty.c */
void glop_val(FILE *fd);

/* opcd_funcs.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* opcd_funcs1.c */
void nop(stack_t **stack, unsigned int line_number);

/* opcd_structure.c */
void selector(char *op_str, stack_t **stack, unsigned int line_number);

/* opcd_tok.c */
int is_num(char *n);
void _strtok(char *str, stack_t **stack, unsigned int line_number);

/* free_dlistint.c */
void free_dlistint(stack_t *head);

#endif
