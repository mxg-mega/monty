#include "monty.h"

/**
 * get_opcode_instruc - gets the opcode function and returns it
 * @opcode: the opcode string
 *
 * Return: NULL if invalid else function
 */
void get_opcode_instruc(char *opcode)
{
	int i = 0;
	instruction_t instuctions[] = {
		{"push", push},
		{"pall", pall},
	}
	while (strcmp(instructions[i]->opcode, opcode) != 0)
	{
		i++;
	}
}

