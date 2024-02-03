#include "monty.h"

/**
 * swap - function swaps the top two elements of the stack.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *tmp_n = NULL;

	if (is_Empty(*stack) == 0 || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		errorIndicator++;
		return;
	}

	tmp = *stack;
	tmp_n = (*stack)->next;
	tmp->next = tmp_n->next;
	tmp->prev = tmp_n;

	tmp_n->next->prev = tmp;
	tmp_n->next = tmp;
	tmp_n->prev = NULL;
	*stack = tmp_n;

}
