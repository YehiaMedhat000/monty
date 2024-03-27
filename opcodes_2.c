#include "monty.h"

/**
 * _div - The function implementation for div
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void _div(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *st = *stack;

	while (st)
	{
		st = st->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, CANNOT_DIV, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, ZERO_DIV, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	st = (*stack)->next;
	st->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - The function implementation for mul
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *st = *stack;

	while (st)
	{
		st = st->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, CANNOT_MUL, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	st = (*stack)->next;
	st->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - The function implementation for mod
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void mod(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *st = *stack;

	while (st)
	{
		st = st->next;
		i++;
	}

	if (i < 2)
	{
		fprintf(stderr, CANNOT_MOD, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, ZERO_DIV, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	st = (*stack)->next;
	st->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - The function implementation for pchar
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, CANNOT_PCHAR, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		fprintf(stderr, CANNOT_PCHAR_RANGE, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - The function implementation for pstr
 * byte code in monty
 * @stack: The stack used in execution 
 * @line_number: The line number where the byte
 * code is found
 * Return: Nothing (void)
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *st = *stack;
	(void)line_number;

	while (st && st->n > 0 && st->n < 128)
	{
		printf("%c", st->n);
		st = st->next;
	}
	printf("\n");
}
