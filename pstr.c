#include "monty.h"

/**
 * pstr - function prints the char at the top of the stack,
 * followed by a new line.
 * @stack: top or head of stack
 * @line_number: line at which the command is
 *
 * Return: no return
 */
void pstr(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (is_Empty(*stack) == 0)
	{
		putchar('\n');
		prep_exit(*stack);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->n <= 0 || tmp->n > 127)
		{
			putchar('\n');
			return;
			/*prep_exit(*stack);
			exit(EXIT_FAILURE);*/
		}
		putchar(tmp->n);
		tmp = tmp->next;
	}
	putchar('\n');
}
