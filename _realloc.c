#include "monty.h"

/**
 * _realloc - function reallocates memory
 * @ptr: the pointer to reallocate memory
 * @oldsize: old mem size
 * @newsize: new mem size
 *
 * Return: new mem or Null if fail
 */
void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize)
{
	void *newArray = NULL;
	unsigned char *old = NULL, *new = NULL;
	unsigned int i = 0;

	if (ptr == NULL)
	{
		return (malloc(newsize));
	}
	if (newsize == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (oldsize == newsize)
	{
		return (ptr);
	}

	newArray = malloc(newsize);
	if (newArray == NULL)
	{
		return (NULL);
	}

	old = ptr;
	new = newArray;
	for (i = 0; i < oldsize && i < newsize; i++)
	{
		new[i] = old[i];
	}
	free(ptr);
	return (new);
}
