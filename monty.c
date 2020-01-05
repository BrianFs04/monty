#include "monty.h"
glova_t glop;

/**
 * glop_val - global variable values
 * @fd: file descriptor
 */
void glop_val(FILE *fd)
{
	glop.nline = 1;
	glop.head = NULL;
	glop.buff = NULL;
	glop.fd = fd;
	glop.size = 0;
}
/**
 * main - monty transcriptor
 * @argc: argument count
 * @argv: argument vectors
 * Return: int
 */
int main(int argc, char **argv)
{
	char *str_tok;

	glop_val(glop.fd);

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	glop.fd = fopen(argv[1], "r");

	if (glop.fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&(glop.buff), &glop.size, glop.fd) != -1)
	{
		if (*glop.buff != '\n')
		{
			str_tok = strtok(glop.buff, "\n");
			_strtok(str_tok, &glop.head, glop.nline);
		}
		glop.nline++;
	}
	free_glop();
	return (0);
}
