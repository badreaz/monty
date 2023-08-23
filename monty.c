#include "monty.h"

info_t info;

/**
 * main - Monty ByteCodes files interpreter.
 * @ac: argument count.
 * @av: argument vector.
 *
 * return: 0.
 */
int main(int ac, char *av[])
{
	unsigned int lnum = 0;
	int size;
	stack_t *stack = NULL;

	lnum++;
	if (ac != 2)
	{
		fprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.file = open(av[1], O_RDONLY);
	if (!info.file)
	{
		fprintf(2, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	size = fread(info.file, &info.line, 1000);
	while (size != 0)
	{
		if (get_opcode())
			get_opcode()(&stack, lnum);
		size = fread(info.file, info.line, 1000);
	}
	close(info.file);
	return (0);
}
