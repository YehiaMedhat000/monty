#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

#define ARGS_ERR "USAGE: monty file\n"
#define FILE_OPEN_ERR "Error: Can't open file %s\n"
#define CANNOT_MALLOC "Error: malloc failed\n"
#define NO_INT_ARG "L%u: usage: push integer\n"
#define CANNOT_PINT "L%u: can't pint, stack empty\n"
#define CANNOT_SWAP "L%u: can't swap, stack too short\n"
#define CANNOT_POP "L%u: can't pop an empty stack\n"
#define CANNOT_ADD "L%u: can't add, stack too short\n"
#define CANNOT_SUB "L%u: can't sub, stack too short\n"
#define CANNOT_PCHAR "L%u: can't pchar, stack empty\n"
#define CANNOT_PCHAR_RANGE "L%u: can't pchar, value out of range\n"
#define CANNOT_MOD "L%u: can't mod, stack too short\n"
#define CANNOT_MUL "L%u: can't mul, stack too short\n"
#define CANNOT_DIV "L%u: can't div, stack too short\n"
#define ZERO_DIV "L%u: division by zero\n"
#define UNKNOWN_INSTR "L%u: unknown instruction %s\n"

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

/**
 * struct vars_s - Strcture for easier access
 * of some variables associated with processes
 * @type: Specifies type, stack or queue
 * @lcount: Line number
 * @param: second parameter to the opcode
 * @stack: The stack to be used in execution
 * @file: file pointer to the monty script
 * @line: The line obtained from file per time
 */

typedef struct vars_s
{
	int type;
	unsigned int lcount;
	char *param;
	stack_t *stack;
	FILE *file;
	char *line;
} vars_t;

extern vars_t vars;

/* opcodes_0.c */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* opcodes_1.c */
void queue(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* opcodes_2.c */
void _div(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);

/* opcodes_3.c and others */
void rotr(stack_t **stack, unsigned int line_number);
void init_vars(FILE *file);
void free_vars(void);
FILE *validate_line(int ac, char **av);

/* execute.c */
char ***parse_file(FILE *file);
void wrapper(char *file_name);

/* stack.c */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* utils.c */
void (*get_func(char *code))(stack_t **stack, unsigned int line_number);
int _strcmp(char *p1, char *p2);

#endif /* MONTY_H */
