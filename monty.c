#include "monty.h"

/**
 * main - entry point
 * @ac: argument counter
 * @av: argument vector
 * Return: always return 0
 */

int main(int ac, char **av)
{
	_init_check(ac);
	_init_stream(av);

	exec_loop();

	_free_datas();
	return (0);
}
