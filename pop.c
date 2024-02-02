#include "monty.h"

/**
 * pop - function removes the top element of the stack.
 * @stack: the stack that a data will be pushed to
 * @line_number: the line number
 *
 * Return - nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		errorIndicator++;
		return;
	}

	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
