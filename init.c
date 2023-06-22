#include "monty.h"

/**
 * _init_stream - inti
 * @av: argument vector
 *
 * Return: nothing
 */

void _init_stream(char **av)
{
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
	free(datas.file);
	free(datas.stream);

	if (datas.input)
		free(datas.input);
	free_dlistint(datas.stack);
}
