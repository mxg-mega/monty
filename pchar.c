#include "monty.h"

/**
 * pchar - function prints the char at the top of the stack,
 * followed by a new line.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (is_Empty(*stack) == 0)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	if (putchar((*stack)->n) == EOF)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	putchar('\n');
}
