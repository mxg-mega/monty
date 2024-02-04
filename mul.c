#include "monty.h"

/**
 * _mul - function multiplies the top two elements of the stack.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	unsigned int product = 0;

	if (is_Empty(*stack) == 0 || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	product = (*stack)->next->n * tmp->n;
	(*stack)->next->n = product;
	*stack = (*stack)->next;
	free(tmp);

}
