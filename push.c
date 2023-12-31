#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @stack: doubly linked list stack.
 * @line_number: the file line number.
 */
void push(stack_t **stack, unsigned int line_number)
{
	int notint = 0, i;
	char c;


	if (info.value)
	{
		for (i = 0; (c = info.value[i]); i++)
		{
			if (c == '-')
				continue;
			if (c < 48 || c > 57)
			{
				notint = 1;
				break;
			}
		}
	}
	if (!info.value || notint)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(info.file);
		free_stack(*stack);
		free(info.line);
		exit(EXIT_FAILURE);
	}
	if (info.queue == 0)
		add_dnodeint(stack, atoi(info.value));
	else
		add_dnodeint_end(stack, atoi(info.value));
}
