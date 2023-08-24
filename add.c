#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || (*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(info.file);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}
