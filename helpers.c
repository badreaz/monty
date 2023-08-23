#include "monty.h"

/**
 * print_stack - prints all elements of a stack_t list.
 * @h: pointer to the head of double linked list.
 *
 * Return: number of nodes.
 */
size_t print_stack(const stack_t *h)
{
	size_t i;

	for (i = 0; h; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}

/**
 * add_dnodeint - adds a new node at the beginning of a list.
 * @head: pointer to the head of list.
 * @n: int to add.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head)
		(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * free_stack - frees a stack_t list.
 * @head: pointer to the head of list.
 */
void free_stack(stack_t *head)
{
	if (head)
	{
		free_stack(head->next);
		free(head);
	}
}

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 *  stack_t linked list.
 * @head: pointer to the head of list.
 * @index: node position.
 *
 * Return: 1 in success, otherwise -1.
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i;
	stack_t *ptr = *head;

	if (*head == NULL)
		return (-1);
	for (i = 0; ptr; i++)
	{
		if (i == index)
		{
			if (ptr->prev && ptr->next)
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			else if (ptr->prev)
				ptr->prev->next = NULL;
			else
			{
				*head = ptr->next;
				ptr->next->prev = NULL;
			}
			free(ptr);
			return (1);
		}
		ptr = ptr->next;
	}
	return (-1);
}