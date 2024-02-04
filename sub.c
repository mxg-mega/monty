#include "monty.h"

/**
 * sub - function subtracts the top two elements of the stack.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	unsigned int diff = 0;

	if (is_Empty(*stack) == 0 || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	diff = (*stack)->next->n - tmp->n;
	(*stack)->next->n = diff;
	*stack = (*stack)->next;
	free(tmp);

}
