#include "monty.h"

/**
 * _init - check basics
 *
 * Return: nothing
 */

void _init()
{
	char *error;

	if (ac != 2)
	{
		error = error_usage();
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
		exit(EXIT_FAILURE);
	}

	datas = malloc(sizeof(data_t));
	if (datas == NULL)
	{
		error = error_malloc();
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector
 * Return: always return 0
 */

int main(int ac, char **av)
{
	_init();
	_strcpy(datas->file, av[1]);

	datas->stream = fopen(av[1], "r");

	if (datas->stream == NULL)
	{
		datas->input =  error_open_stream();
		write(STDERR_FILENO, datas->input, _strlen(datas->input));
	}

	if (datas->stream != NULL)
	{
		exec_loop();
	}

	return 0;
}
