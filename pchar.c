#include "monty.h"

/**
 * pchar - prints the char at the top of stackk.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(info.file);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(info.file);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
