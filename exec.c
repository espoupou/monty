#include "monty.h"

/**
 * exec_loop - the execution loop
 *
 * Return: nothing
*/

void exec_loop(void)
{
	int loop = 1;
	size_t size = 256;
	ssize_t nlines = 0;
	char *op;
	void (*f)(stack_t **stack, unsigned int line_number);

	while (loop)
	{
		nlines = getline(&datas.input, &size, datas.stream);
		if (nlines == -1)
		{
			loop = 0;
			continue;
		}

		op = _strtok(datas.input, " \n\t");
		if (op == NULL || *op == '#')
		{
			datas.line++;
			free(datas.input);
			datas.input = NULL;
			continue;
		}

		f = get_op_function(op);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", datas.line, op);
			_free_datas();
			exit(EXIT_FAILURE);
		}
		datas.arg = _strtok(NULL, " \n\t");
		f(&datas.stack, datas.line);
		datas.line++;
		free(datas.input);
		datas.input = NULL;
	}
}
