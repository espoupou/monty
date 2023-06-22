#include "monty.h"

/**
 * check_stop - check if we have a separator
 * @c: the character
 *
 * Return: 0 or 1
 */

int check_stop(char c)
{
	int i = 0;

	switch (c)
	{
		case ' ':
		case '\t':
		case '\n':
		case '\0':
			i = 1;
	}
	return (i);
}
/**
 * clean - clean the input
 * @input: inputed
 *
 * Return: status 0 or 1
 */

int clean(char *input)
{
	char *p;

	while (*input == ' ' || *input == '\t')
		input++;

	p = input;
	while (*p != '\n' && *p != '\0')
	{
		if (p != input && check_stop(*p) && check_stop(*(p - 1)))
			_memcpy(p, p + 1, _strlen(p + 1));

		p++;
	}

	return (1);
}

/**
 * exec_loop - the execution loop
 *
 * Return: status 0 or 1
 */

int exec_loop(void)
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
		if (op == NULL)
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

	return (0);
}
