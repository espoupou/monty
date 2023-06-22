#include "monty.h"

/**
 * _init_check - check basics
 * @ac: argument counter
 *
 * Return: nothing
 */

void _init_check(int ac)
{
/*	char *error; */

	if (ac != 2)
	{
/*		error = error_usage(); */
		dprintf(2, "USAGE: monty file\n");
		/* write(STDERR_FILENO, error, _strlen(error)); */
/*		free(error); */
		exit(EXIT_FAILURE);
	}

	datas.input = NULL;
	datas.arg = NULL;
	datas.stack = NULL;
	datas.line = 0;
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

void _free_datas(void)
{
	free(datas.file);
	free(datas.stream);

	if (datas.input)
		free(datas.input);
	free_dlistint(datas.stack);
}
