#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t instructions[];

char** getcommand(char *buffer);
void free_line(char **array);
int is_Empty(stack_t *stack);
int is_validNumber(const char *str);

extern void push(stack_t **stack, unsigned int line_number);
extern void pall(stack_t **stack, unsigned int line_number);

void clear_stack(stack_t *head);
instruction_t *get_opcode_instruc(char *opcode);
int stringToInteger(const char *str);

#endif /*_MONTY_H_*/
