#include "monty.h"

/**
 * get_opcode - get the function for the opcode.
 * 
 * Return: poimter to the opcode function.
 */
void (*get_opcode(void))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	int i;
	char *opcode, *element;

	opcode = strtok(info.line, " \n");
	element= strtok(NULL, " \n");
	if (element)
		info.value = atoi(element);
	for (i = 0; ops[i].opcode; i++)
	{
		if (strcmp(opcode, ops[i].opcode) == 0)
			return (ops[i].f);
	}
	return (NULL);
}
