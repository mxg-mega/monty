#include "monty.h"
#define MAX_ARGS 3
/**
 * getcommand - function tokenizes the line of buffer taken to cmd and arg
 * @buffer: buffer taken
 *
 * Return: 2d array or NULL if malloc fail or any fail
 */
char **getcommand(char *buffer)
{
	char *token = NULL, *delim = " \n\t";
	int argCount = 0, i = 0;
	char **args = malloc(sizeof(char *) * MAX_ARGS);

	if (args == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < MAX_ARGS; i++)
	{
		args[i] = NULL;
	}

	token = strtok(buffer, delim);
	while (token != NULL && argCount < MAX_ARGS - 1)
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
	args[MAX_ARGS - 1] = NULL;
	return (args);
}
