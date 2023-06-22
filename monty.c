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

	_init_stream(av);

	exec_loop();

	_free_datas();
	return (0);
}
