#include "monty.h"

/**
 * get_opcode - get the function for the opcode.
 * @opcode: opcode.
 *
 * Return: poimter to the opcode function.
 */
void (*get_opcode(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}};
	int i;

	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
	}
	return (NULL);
}
