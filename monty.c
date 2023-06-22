#include "monty.h"

/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector
 * Return: always return 0
 */

int main(int ac, char **av)
{
	char *error;

	if (ac != 2)
	{
		error = error_usage();
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
		exit(EXIT_FAILURE);
	}

	_init_check(ac);
	_init_stream(av);

	exec_loop();

	_free_datas();
	return (0);
}
