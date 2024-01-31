#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count_args(char **cmd);
char** getcommand(char *buffer);
void free_line(char **array);

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
	char *buffer = malloc(sizeof(char) * 1024);
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
		++lineCount;
		cmd = getcommand(buffer);
		if (cmd == NULL)
		{
			free(buffer);
			fclose(file);
			fprintf(stderr, "out of bound, to many or little arguments %s at line %u\n", cmd[0], lineCount);
			free_line(cmd);
			if (head != NULL)
			{
				clear_stack(head);
			}
			return (EXIT_FAILURE);
		}

		if (cmd[0] == NULL)
		{
			free_line(cmd);
			continue;
		}

		instruct = get_opcode_instruc(cmd[0]);
		if (instruct == NULL)
		{
			if (head != NULL)
			{
				clear_stack(head);
			}
			fprintf(stderr, "L%u: unknown instruction %s\n", lineCount, cmd[0]);
			free(buffer);
			fclose(file);
			free_line(cmd);
			return (EXIT_FAILURE);
		}
		if (cmd[1] != NULL)
		{
			cmdArg = stringToInteger(cmd[1]);
			if (cmdArg == -1 || cmd[2] != NULL)
			{
				free(buffer);
				fclose(file);
				free_line(cmd);
				if (head != NULL)
				{
					clear_stack(head);
				}
				fprintf(stderr, "L%u: usage: push integer\n", lineCount);
				return (EXIT_FAILURE);
			}
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

char** getcommand(char *buffer)
{
	char *token = NULL, *delim = " \n\t";
	int argCount = 0, i = 0;
	char **args = malloc(sizeof(char*) * 3);

	if (args == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < 3; i++)
	{
		args[i] = NULL;
	}
	token = strtok(buffer, delim);
	while (token != NULL && argCount < 2)
	{
		args[argCount] = malloc(strlen(token) + 2);
		if (args[argCount] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			return (NULL);
		}
		strcpy(args[argCount], token);
		args[argCount][strlen(token)] = '\0';
		argCount++;
		token = strtok(NULL, delim);
	}
	args[2] = NULL;
	return (args);
}

int count_args(char **cmd)
{
	int count = 0, i = 0;

	if (cmd == NULL)
	{
		return(-1);
	}
	for (i = 0; cmd[i] != NULL; i++)
	{
		count++;
	}
	return (count);
}

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
