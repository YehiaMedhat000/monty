#include "monty.h"

/**
 * push - The function for the opcode push
 * @line_number: The line where it's found
 * @stack: The stack to be used for execution
 * Return: Nothing (void)
 */

void push(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (!vars.param)
	{
		fprintf(stderr, NO_INT_param, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}
	while (vars.param[i] != '\0')
	{
		if (!isdigit(vars.param[i]) && vars.param[i] != '-')
		{
			fprintf(stderr, NO_INT_ARG, line_number);
			free_vars();
			exit(EXIT_FAILURE);
		}
		i++;
	}
	i = atoi(vars.param);
	if (vars.type == 1)
		add_dnodeint(stack, i);
	else
		add_dnodeint_end(stack, i);
}

/**
 * pall - The function for the opcode pall
 * @line_number: The line where it's found
 * @stack: The stack to be used for execution
 * Return: Nothing (void)
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *st;
	(void)line_number;

	st = *stack;

	while (st)
	{
		printf("%d\n", st->n);
		st = st->next;
	}
}

/**
 * pop - The function for the opcode pop
 * @line_number: The line where it's found
 * @stack: The stack to be used for execution
 * Return: Nothing (void)
 */

void pop(stack_t **stack, unsigned int line_number);
{
	stack_t *st;

	if (!stack || !*stack)
	{
		fprintf(stderr, CANNOT_POP, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}
	st = *stack;
	*stack = (*stack)->next;
	free(st);
}

/**
 * pint - The function for the opcode pint
 * @line_number: The line where it's found
 * @stack: The stack to be used for execution
 * Return: Nothing (void)
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!*stack)
	{
		fprintf(stderr, CANNOT_PINT, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * swap - The function for the opcode swap
 * @line_number: The line where it's found
 * @stack: The stack to be used for execution
 * Return: Nothing (void)
 */

void swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, CANNOT_SWAP, line_number);
		free_vars();
		exit(EXIT_FAILURE);
	}

	st = *stack;
	*stack = (*stack)->next;
	st->next = (*stack)->next;
	st->prev = *stack;
	(*stack)->next = st;
	(*stack)->prev = NULL;
}
