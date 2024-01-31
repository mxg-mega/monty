#include "monty.h"

/**
 * pall - function prints out all numbers in a stack
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (is_Empty(*stack) == 0)
	{
		fprintf(stderr, "Stack is Empty, error at line %u\n", line_number);
		return;
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
