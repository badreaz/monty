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
	ssize_t ret;
	stack_t *stack = NULL;
	size_t size;
	char *opcode, *element;

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
		opcode = strtok(info.line, " \n");
		element= strtok(NULL, " \n");
		if (element)
			info.value = atoi(element);

		if (get_opcode(opcode))
			get_opcode(opcode)(&stack, lnum);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, opcode);
			fclose(info.file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		ret = getline(&info.line, &size, info.file);
	}
	fclose(info.file);
	return (0);
}
