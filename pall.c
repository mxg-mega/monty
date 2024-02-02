#include "monty.h"

/**
 * pall - function prints out all numbers in a stack
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (is_Empty(*stack) == 0)
	{
		errorIndicator = 1;
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
