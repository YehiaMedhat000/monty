#include "monty.h"

/**
 * parse_file - Parses file and passes
 * the results in a linked list struct
 * @file: File pointer to parse
 * @line: The struct to use for storing data
 * Return: triple pointer to the contents
 * of the file, NULL otherwise
 */

char ***parse_file(FILE *file)
{
	char ***parsed = malloc(sizeof(char ***));
	size_t n = 10;
	char *buff = malloc(n);
	int check = 0;

	*parsed = malloc(sizeof(char **));

	if (!parsed || !*parsed || !buff)
		return (NULL);

	do {
		**parsed = malloc(sizeof(char *) * 2);
		check = getline(&buff, &n, file);
		**parsed = strtok(buff, " \n\t");
		if (strcmp(**parsed++, "push"))
			return (NULL);
		**parsed = strtok(NULL, " \n\t");
		(*parsed)++;
		*parsed = malloc(sizeof(char **));
	} while (check != -1);
	return (parsed);
}

/*
void (*get_func(char *func))(stack_t **stack, unsigned int line_number)
{
	instruction_t codes[3] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL},
	};
	int i = 0;

	while (codes[i].opcode)
	{
		if (!strcmp(codes[i].opcode, func))
			break;
		i++;
	}
	return (codes[i].f);
}
*/
/**
 * wrapper_func - executes the last two functions
 * until the end of file or until an error is found
 * @file_name: File name to use
 * Return: Nothing (void)
 */
/*
void wrapper(char *file_name)
{
	stack_t *stack = malloc(sizeof(stack_t));
	int check = 0;
	FILE *file = fopen(file_name, "r");
	void (*func)(stack_t **, unsigned int);

	do {
		check = parse_file(file, args);
		func = get_func(args->code);
		func(&stack, 1);
	} while (check != -1);

	free(stack);
	fclose(file);
}
*/
