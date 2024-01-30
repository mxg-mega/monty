#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
	int lineCount = 0;
	size_t buffsize = 1024;
	char **cmd = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "monty file\n");
		exit(EXIT_FAILURE);
	}
	if (buffer == NULL)
	{
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
		printf("command: %s, length of command: %lu\n", buffer, strlen(buffer));
		cmd = getcommand(buffer);
		if (cmd == NULL)
		{
			free(buffer);
			fclose(file);
			free_line(cmd);
			fprintf(stderr, "out of bound, to many or little arguments at line %d\n", lineCount);
			return (EXIT_FAILURE);
		}
		printf("command: %s - argument: %s\n", cmd[0], cmd[1]);
		free_line(cmd);
	}
	free(buffer);
	fclose(file);
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
	while (token != NULL && argCount <= 2)
	{
		args[argCount] = malloc(strlen(token) + 2);
		if (args[argCount] == NULL)
		{
			return (NULL);
		}
		strcpy(args[argCount], token);
		args[argCount][strlen(token)] = '\0';
		argCount++;
		token = strtok(NULL, delim);
	}
	if (argCount > 2)
	{
		free_line(args);
		return (NULL);
	}
	args[2] = NULL;
	return (args);
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
