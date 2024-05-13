#include "monty.h"

/**
 * push - The function implementation
 * for the push byte code in monty
 * @stack: The stack used
 * @line_number: The line number where
 * the code is found
 * Return: Nothing (void)
 */

void push(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("Hey there this is supposed to work\n");
}

/**
 * pall - The function implementation
 * for the pall byte code in monty
 * @stack: The stack used
 * @line_number: The line number where
 * the code is found
 * Return: Nothing (void)
 */

void pall(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	printf("This is from pall\n");
}
