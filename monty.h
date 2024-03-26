#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define NO_ARGS_ERR "USAGE: monty file\n"
#define FILE_OPEN_ERR "Error: Can't open file %s\n"
#define CANNOT_MALLOC "Error: malloc failed\n"
#define NO_INT_ARG "L%s: usage: push integer\n"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 */

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct code_line_s - Auxiliary strcut
 * for the parse_file function to help
 * get the contents of a code line in
 * an organized way
 * @opcode: The opcode obtained from
 * parsing the line
 * @n: The value associated with opcode
 */

typedef struct code_line_s
{
	char *opcode;	
	int n;
} code_line_t;

/* Function Prototypes */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void parse_file(FILE *file, code_line_t *args);
void match_func(char *func, stack_t **stack, unsigned int n);

#endif /* MONTY_H */
