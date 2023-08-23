#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: doubly linked list stack.
 * @line_number: the file line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		if (!info.value)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		add_dnodeint(stack, info.value);
	}
}
