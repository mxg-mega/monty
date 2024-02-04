#include "monty.h"

/**
 * _div - function divides the top two elements of the stack.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	unsigned int sum = 0;

	if (is_Empty(*stack) == 0 || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sum = (*stack)->next->n / tmp->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	free(tmp);

}
