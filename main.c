#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_args(char **cmd);

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}
};

ops_t container = {NULL, NULL, NULL};

/**
 * main - maint entry point
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	FILE *file;
	char *buffer = malloc(sizeof(char) * 1024), *push = "push";
	unsigned int lineCount = 0;
	int cmdArg = 0;
	size_t buffsize = 1024;
	instruction_t *instruct = NULL;
	stack_t *head = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	memset(buffer, 0, buffsize);
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	container.file = file;
	while (fgets(buffer, buffsize, file) != NULL)
	{
		++lineCount;
		container.buffer = buffer;
		container.cmd = getcommand(container.buffer);
		if (container.cmd == NULL)
		{
			prep_exit(head);
			exit(EXIT_FAILURE);
		}

		if (container.cmd[0] == NULL)
		{
			free_line(container.cmd);
			continue;
		}

		instruct = get_opcode_instruc(container.cmd[0]);
		if (instruct == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", lineCount, container.cmd[0]);
			prep_exit(head);
			exit(EXIT_FAILURE);
		}

		if (strcmp(instruct->opcode, push) == 0)
		{
			if (container.cmd[1] == NULL || is_validNumber(container.cmd[1]) == 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", lineCount);
				prep_exit(head);
				exit(EXIT_FAILURE);
			}
			cmdArg = stringToInteger(container.cmd[1]);
			instruct->f(&head, (unsigned int)cmdArg);
		}
		else
		{
			instruct->f(&head, lineCount);
		}
		free_line(container.cmd);
	}
	free(container.buffer);
	fclose(container.file);
	clear_stack(head);
	return (EXIT_SUCCESS);
}

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

/**
 * count_args - function counts the number of arguments
 * @cmd: a 2d array of the command
 *
 * Return: number of args or -1 if fail
 */
int count_args(char **cmd)
{
	int i = 0;

	if (cmd == NULL)
	{
		return (-1);
	}
	for (i = 0; cmd[i] != NULL; i++)
	{
	}
	return (i);
}

/**
 * free_line - function frees the memory of 2d array
 * @array: 2d array
 *
 * Return: no return
 */
void free_line(char **array)
{
	int i = 0;

	if (array == NULL)
	{
		return;
	}
	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
