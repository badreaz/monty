#include "monty.h"

/**
 * pstr - prints the string at the topp of stack.
 * @stack: doubly linked list stack.
 * @line_number:file line_number.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *h = *stack;

	while (h && h->n > 0 && h->n < 127)
	{
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
