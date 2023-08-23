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
	int ret;
	stack_t *stack = NULL;
	size_t size;

	lnum++;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.file = fopen(av[1], "r");
	if (!info.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	ret = getline(&info.line, &size, info.file);
	while (ret != 0)
	{
		if (get_opcode())
			get_opcode()(&stack, lnum);
		ret = getline(&info.line, $size, info.file);
	}
	fclose(info.file);
	return (0);
}
