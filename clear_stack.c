#include "monty.h"

/**
  * clear_stack - function frees the linked list
  * @head: the head of the link
  *
  * Return: No return
  */
void clear_stack(stack_t *head)
{
	stack_t *current = NULL, *temp = NULL;

	if (head == NULL)
	{
		return;
	}
	current = head;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
