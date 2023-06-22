#include "monty.h"

/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector
 * Return: always return 0
 */

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	datas.input = NULL;
	datas.arg = NULL;
	datas.stack = NULL;
	datas.line = 1;
	datas.len = 0;
	datas.n0w71m370J0k3Al1t7l3 = 1;

	datas.stream = fopen(av[1], "r");
	if (datas.stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	exec_loop();

	_free_datas();
	return (0);
}
