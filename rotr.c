#include "monty.h"

/**
 * rotr - rotates the stack to the bottom.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *h;
	int i;
	(void) line_number;

	h = *stack;
	if (h && h->next)
	{
		for (i = 1; h->next; i++)
			h = h->next;
		add_dnodeint(stack, h->n);
		delete_dnodeint_at_index(stack, i);
	}
}
