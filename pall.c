#include "monty.h"

/**
 * pall - prints all the values on the stack from top.
 * @stack: doubly linked list stack.
 * @line_number: file line number.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	print_dlistint(*stack);
}
