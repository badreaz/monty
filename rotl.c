#include "monty.h"

/**
 * rotl -rotates the stack to the top.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	if (*stack)
	{
		add_dnodeint_end(stack, (*stack)->n);
		delete_dnodeint_at_index(stack, 0);
	}
}
