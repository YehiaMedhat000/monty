#include "monty.h"

/**
 * queue - The function implementation for queue
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void queue(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	vglo.lifo = 0;
}

/**
 * stack - The function implementation for stack
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void stack(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	vglo.lifo = 1;
}

/**
 * add - The function implementation for add
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void add(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *st = NULL;

	st = *stack;

	while (st)
	{
		st = st->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, CANNOT_ADD, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	st = (*stack)->next;
	st->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - The function implementation for nop
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - The function implementation for sub
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *st = NULL;

	st = *stack;

	while (st)
	{
		st = st->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, CANNOT_SUB, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	st = (*stack)->next;
	st->n -= (*stack)->n;
	pop(stack, line_number);
}

