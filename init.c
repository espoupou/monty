#include "monty.h"

/**
 * _init_ - inti
 * @av: argument vector
 *
 * Return: nothing
 */

void _init_(char **av)
{
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
}

/**
 * _free_datas - free all data
 *
 * Return: nothing
 */

void _free_datas(void)
{
	if (datas.stream)
		fclose(datas.stream);

	if (datas.input)
		free(datas.input);

	free_dlistint(datas.stack);
}
