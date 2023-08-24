#include "monty.h"
#define _GNU_SOURCE

info_t info = {NULL, NULL, NULL, 0};

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
	ssize_t ret = 1;
	stack_t *stack = NULL;
	size_t size = 2000;
	char *opcode, *line;

	if (ac != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file = fopen(av[1], "r");
	if (!file)
		fprintf(stderr, "Error: Can't open file %s\n", av[1]), exit(EXIT_FAILURE);
	line = malloc(sizeof(char) * size);
	info.file = file;
	while (ret != EOF)
	{
		ret = getline(&line, &size, file);
		info.line = line;
		opcode = strtok(line, " \n\t");
		info.value = strtok(NULL, " \n\t");
		if (!opcode || ret == EOF || opcode[0] == '#') 
			continue;
		if (!get_opcode(opcode))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, opcode);
			fclose(info.file);
			free_stack(stack);
			free(line);
			exit(EXIT_FAILURE);
		}
		get_opcode(opcode)(&stack, lnum);
		lnum++;
	}
	fclose(info.file);
	free_stack(stack);
	free(line);
	return (0);
}
