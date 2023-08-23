#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!*stack || (*stack)->next)
	{
		fprintf(2, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}
