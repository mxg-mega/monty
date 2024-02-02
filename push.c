#include "monty.h"

/**
 * push - function pushes a data into a stack(Queue)
 * @stack: the stack that a data will be pushed to
 * @line_number: the line number
 *
 * Return - nothing
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack = NULL;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		errorIndicator = 1;
		return;
	}
	new_stack->n = line_number;
	new_stack->prev = NULL;
	new_stack->next = NULL;
	if (is_Empty(*stack) == 0)
	{
		*stack = new_stack;
	}
	else
	{
		(*stack)->prev = new_stack;
		new_stack->next = *stack;
		*stack = new_stack;
	}
}
