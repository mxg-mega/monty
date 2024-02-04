#include "monty.h"

/**
 * _mod - function computes the rest of the division of
 * the second top element of the stack by
 * the top element of the stack.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	unsigned int mod = 0;

	if (is_Empty(*stack) == 0 || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	mod = (*stack)->next->n % tmp->n;
	(*stack)->next->n = mod;
	*stack = (*stack)->next;
	free(tmp);

}
