#include "monty.h"

/**
 * _init_stream - inti
 * @av: argument vector
 *
 * Return: nothing
 */

void _init_stream(char **av)
{
	char *error;

	datas.file = malloc(sizeof(av[1]));
	if (datas.file == NULL)
	{
		error = error_malloc();
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
		exit(EXIT_FAILURE);
	}
	_strcpy(datas.file, av[1]);

	datas.stream = fopen(av[1], "r");

	if (datas.stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s", av[1]);
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
