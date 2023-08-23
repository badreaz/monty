#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: doubbly linked list stack.
 * @line_number: file line number.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(2, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	delete_dnodeint_at_index(stack, 0);
}
