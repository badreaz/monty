#include "monty.h"

/**
 * main - Monty ByteCodes files interpreter.
 * @ac: argument count.
 * @av: argument vector.
 *
 * return: 0.
 */
int main(int ac, char **av)
{
	int file;

	if (ac != 2)
	{
		fprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = open(ac[1], O_RDONLY);
	if (!file)
	{
		fprintf(2, "Error: Can't open file %s\n", ac[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		fread(file, &line, 1000);
	}
	close(file);
	return (0);
}
