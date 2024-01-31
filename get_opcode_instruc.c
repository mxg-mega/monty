#include "monty.h"

/**
 * get_opcode_instruc - gets the opcode function and returns it
 * @opcode: the opcode string
 *
 * Return: a pointer to an instruction or NULL if not found
 */
instruction_t *get_opcode_instruc(char *opcode)
{
	int i = 0, len = 0;
	static instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
	};

	if (opcode == NULL)
	{
		return (NULL);
	}

	len = sizeof(instructions) / sizeof(instructions[0]);
	for (i = 0; i < len; i++)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			return (&instructions[i]);
		}
	}
	return (NULL);
}

