#include "monty.h"
#define _GNU_SOURCE

info_t info = {NULL, NULL, NULL};

/**
 * main - Monty ByteCodes files interpreter.
 * @ac: argument count.
 * @av: argument vector.
 *
 * return: 0.
 */
int main(int ac, char *av[])
{
	FILE *file;
	unsigned int lnum = 1;
	ssize_t ret;
	stack_t *stack = NULL;
	size_t size = 2000;
	char *opcode, *line;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(sizeof(char) * size);
	ret = getline(&line, &size, file);
	info.file = file;
	while (ret != EOF)
	{
		info.line = line;
		if (line[0] == '-')
			continue;
		opcode = strtok(line, " \n\t");
		info.value = strtok(NULL, " \n\t");
		if (get_opcode(opcode))
			get_opcode(opcode)(&stack, lnum);
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, opcode);
			fclose(info.file);
			free_stack(stack);
			free(line);
			exit(EXIT_FAILURE);
		}
		lnum++;
		ret = getline(&line, &size, file);
	}
	fclose(info.file);
	free_stack(stack);
	free(line);
	return (0);
}
