#include "monty.h"

/**
 * add - function adds the top two elements of the stack.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	unsigned int sum = 0;

	if (is_Empty(*stack) == 0 || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sum = tmp->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	*stack = (*stack)->next;
	free(tmp);

}
