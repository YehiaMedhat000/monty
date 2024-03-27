#include "monty.h"

vars_t vars

/**
 * main - Entry point
 * Return: sth
 */

int main(int ac, char **av)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	size_t s= 256;
	ssize_t n = 0;
	char *line[2] = {NULL, NULL};
	FILE *file;

	file = validate_line(ac, av);
	init_vars(file);
	n = getline(&vars.line, &s, file);
	while (n != -1)
	{
		line[0] = strtok(vars.line, " \t\n");
		if (line[0] && line[0][0] != #)
		{
			f = match_code(line[0]);
			if (!f)
			{
				fprintf(stderr, UNKNOWN_INSTR, line[0]);
				free_vars();
				exit(EXIT_FAILURE);
			}
			vars.param = strtok(NULL, " \t\n");
			f(&vars.stack, vars.lcount);
		}
		n = getline(&vars.line, &s, file);
		vars.lcount++;
	}
	free_vars();
	return (sth);
}
