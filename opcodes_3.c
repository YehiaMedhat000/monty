#include "monty.h"

/**
 * rotr - The function for the byte code rotr
 * @stack: The stack used in execution
 * @line_number: The line number where
 * the code is found
 * Return: Nothing (void)
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *st = stack;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;

	while (st)
	{
		st = st->next;
		i++;
	}
	st->prev->next = NULL;
	st->next = *stack;
	st->prev = NULL;
	(*stack)->prev = st;
	*stack = st;
}

/**
 * rotr - The function for the byte code rotr
 * @stack: The stack used in execution
 * @line_number: The line number where
 * the code is found
 * Return: Nothing (void)
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *st1 = NULL;
	stack_t *st2 = NULL;
	(void)line_number;

	if (!*stack || !(*stack)->next)
		return;
	st1 = (*stack)->next;
	st2 = *stack;
	while (!st2->next)
		st2 = st2->next;

	st1->prev = NULL;
	st2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = st2;
	*stack = st1;
}

/**
 * init_vars - Initializes the global
 * struct vars_s
 * @file: File pointer to the monty script
 * Return: Nothing (void)
 */

void init_vars(FILE *file)
{
	vars.type = 1;
	vars.lcount = 1;
	vars.param = NULL;
	vars.stack = NULL;
	vars.file = file;
	vars.line = NULL;
}

/**
 * free_vars - Frees The global strcut
 * vars_s when execution is finished
 * Return: Nothing (void)
 */

void free_vars(void)
{
	free_dlistint(vars_t.head);
	free(vars_t.buffer);
	fclose(vars_t.fd);
}

/**
 * validate_line - Validates that an input
 * line is valid as monty byte code
 * @ac: Arguments count
 * @av: Arguments values
 * Return: FILE *
 */ 

FILE *validate_line(int ac, char **av)
{
	FILE *file;

	if (ac == 1 || ac > 2)
	{
		fprintf(stderr, ARGS_ERR);
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	if (!file)
	{
		fprintf(stderr, FILE_OPEN_ERR, av[1]);
		exit(EXIT_FAILURE);
	}
	return (file);
}

