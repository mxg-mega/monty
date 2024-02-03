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
	{NULL, NULL}
};
int errorIndicator = 0;

/**
 * main - maint entry point
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	FILE *file = NULL;
	char *buffer = malloc(sizeof(char) * 1024), *push = "push";
	unsigned int lineCount = 0;
	int cmdArg = 0;
	size_t buffsize = 1024;
	char **cmd = NULL;
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
	memset(buffer, 0, 1024);
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, buffsize, file) != NULL)
	{
		if (errorIndicator != 0)
		{
			prep_exit(buffer, cmd, head, file);
			exit(EXIT_SUCCESS);
		}
		++lineCount;
		cmd = getcommand(buffer);
		if (cmd == NULL)
		{
			prep_exit(buffer, cmd, head, file);
			exit(EXIT_FAILURE);
		}

		if (cmd[0] == NULL)
		{
			free_line(cmd);
			continue;
		}

		instruct = get_opcode_instruc(cmd[0]);
		if (instruct == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", lineCount, cmd[0]);
			prep_exit(buffer, cmd, head, file);
			exit(EXIT_FAILURE);
		}

		if (strcmp(instruct->opcode, push) == 0)
		{
			if (cmd[1] == NULL || is_validNumber(cmd[1]) == 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", lineCount);
				prep_exit(buffer, cmd, head, file);
				exit(EXIT_FAILURE);
			}
			cmdArg = stringToInteger(cmd[1]);
			instruct->f(&head, (unsigned int)cmdArg);
		}
		else
		{
			instruct->f(&head, lineCount);
		}
		free_line(cmd);
	}
	free(buffer);
	fclose(file);
	clear_stack(head);
	return (EXIT_SUCCESS);
}

/**
 * prep_exit - function prepares and clears all allocated mem before exit
 * @file: the file to be closed
 * @buffer: the buffer
 * @cmd: the commands
 * @stack: head of the stack
 *
 * Return: nothing
 */
void prep_exit(char *buffer, char **cmd, stack_t *stack, FILE *file)
{
	if (buffer == NULL || cmd == NULL || file == NULL)
	{
		return;
	}
	if (stack != NULL)
	{
		clear_stack(stack);
	}
	free(buffer);
	free_line(cmd);
	fclose(file);
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
