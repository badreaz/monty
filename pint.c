#include "mont.h"

/**
 * pint - print the value at the top of the stack.
 * @stack: doubly linked stack.
 * @line_number: file line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
