#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: doubly linked list stack.
 * @line_number: the file line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int element;

	if (stack && *stack)
	{
		element = atoi(info.value);
		if (!element)
		{
			fprintf(2, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		add_dnodeint(stack, element);
	}
}
