#include "monty.h"

/**
 * pint - function prints the value at the top of the stack
 * @stack: the head/top of the stack
 * @line_number: number of the line
 *
 * Return: nothing it exits if error
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("%u\n", line_number);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		errorIndicator++;
		return;
	}
	printf("%u\n", (*stack)->n);
}
