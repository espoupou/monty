#include "monty.h"

/**
 * init_check - check basics
 *
 * Return: status
 */
int init_check()
{
	char *error;
}

/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector
 * Return: always return 0
 */

int main(int ac, char **av)
{
	datas = malloc(sizeof(data_t));

	if (ac != 2)
	{
		datas->input = error_usage();
		write(STDERR_FILENO, datas->input, _strlen(datas->input));
		exit(EXIT_FAILURE);
	}

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
