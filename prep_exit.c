#include "monty.h"

/**
 * prep_exit - function prepares and clears all allocated mem before exit
 * @stack: head of the stack
 *
 * Return: nothing
 */
void prep_exit(stack_t *stack)
{
	if (container.buffer == NULL || container.file == NULL || container.cmd == NULL)
	{
		return;
	}
	if (stack != NULL)
	{
		clear_stack(stack);
	}
	free(container.buffer);
	free_line(container.cmd);
	fclose(container.file);
}


