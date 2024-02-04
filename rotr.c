#include "monty.h"

/**
 * rotr - function rotates the stack to the top.
 * @stack: the stack that a data will be pushed to
 * @line_number: the line number
 *
 * Return - nothing
 */
void rotr(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *tmp = NULL, *last = NULL;

	if (*stack == NULL)
	{
		return;
	}

	tmp = *stack;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	last = tmp;
	last->next = *stack;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = last;

}
