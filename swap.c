#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	int tmp;

	if (!h || !h->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(info.file);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	tmp = h->n;
	h->n = h->next->n;
	h->next->n = tmp;
}
