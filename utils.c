#include "monty.h"

/**
 * match_code - Matches the code name
 * with its proper function pointer
 * @code: The function or code name
 * Return: Nothing (void)
 */
/*
void (*match_code(char *code))(stack_t **stack, unsigned int line_number)
{
	instruction_t *codes = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"queue", queue},
		{"stack", stack},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (codes[i].opcode)
	{
		if (strcmp(codes[i].opcode, code))
			break;
		i++;
	}
	return (codes[i].f);
}
*/

/**
 * _strcmp - implementation of strcmp
 * @p1: The first char pointer
 * @p2: The second char pointer
 * Return: Integer value for the difference
 * between the first two different chars
 */

int _strcmp(char *p1, char *p2)
{
	while (*p1 || *p2)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
