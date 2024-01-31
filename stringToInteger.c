#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * stringToInteger - function converts strings to integers
 * @str: the string
 *
 * Return: the int or -1 if fail
 */
int stringToInteger(const char *str)
{
	char *endptr;
	long result = strtol(str, &endptr, 10);

	if (*endptr != '\0' || str == endptr)
	{
		return (-1);
	}

	if (result < INT_MIN || result > INT_MAX)
	{
		return (-1);
	}
	return ((int)result);
}

/**
 * is_validNumber - function checks if a string contain only numbers
 * @str: the string
 *
 * Return: 0 if true 1 if false
 */
int is_validNumber(const char *str)
{
	while (*str != '\0')
	{
		if ((*str < '0' || *str > '9') && *str != '-')
		{
			return (1);
		}
		str++;
	}
	return (0);
}
