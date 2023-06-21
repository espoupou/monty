#include "monty.h"

/**
 * _init_check - check basics
 * @ac: argument counter
 *
 * Return: nothing
 */

void _init_check(int ac)
{
	char *error;

	if (ac != 2)
	{
		error = error_usage();
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
		exit(EXIT_FAILURE);
	}

	datas.input = NULL;
}

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
	_strcpy(datas.file, av[1]);

	datas.stream = fopen(av[1], "r");

	if (datas.stream == NULL)
	{
		error = error_open_stream();
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
		exit(EXIT_FAILURE);
	}
}

/**
 * _free_datas - free all data
 *
 * Return: nothing
 */

void _free_datas()
{
	free(data.file);
}