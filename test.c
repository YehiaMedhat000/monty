#include "monty.h"

int main(int ac, char **av)
{
	if (ac == 1)
		return (-1);

	printf("_strcmp: %d", _strcmp(av[1], av[2]));
	return (0);
}
