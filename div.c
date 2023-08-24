#include "monty.h"

/**
 * _div - divides the second elment by the first element of stack.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(info.file);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(info.file);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
}
