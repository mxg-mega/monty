#include "monty.h"
#include <stdio.h>
#include <string.h>

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
	char *buffer = NULL;
	int lineCount = 0;
	size_t buffsize = 0;
	char **cmd = {NULL};
	ssize_t read, fail = -1;

	if (ac != 2)
	{
		fprintf(stderr, "monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&buffer, &buffsize, file)) != fail)
	{
		++lineCount;
		cmd = getcommand(buffer);
	}
	free_line(cmd);
	free(buffer);
	fclose(file);
	return (EXIT_SUCCESS);
}

char** getcommand(char *buffer)
{
	char *token = NULL, *delim = " \n\t";
	int argCount = 0;
	char **args = malloc(sizeof(char*) * 2);

	if (args == NULL)
	{
		return (NULL);
	}
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		if (argCount > 2)
		{
			free_line(args);
			return (NULL);
		}
		args[argCount++] = strdup(token);
		token = strtok(NULL, delim);
	}
	return (args);
}
void free_line(char **array)
{
	int i = 0;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
