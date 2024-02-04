#include "monty.h"

/**
 * rotl - function rotates the stack to the top.
 * @stack: the stack that a data will be pushed to
 * @line_number: the line number
 *
 * Return - nothing
 */
void rotl(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
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
	tmp = *stack;

	tmp->prev = last;
	last->next = tmp;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
}
