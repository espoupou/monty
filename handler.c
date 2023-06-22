#include "monty.h"

/**
 * get_op_function - get op function
 * @opc: the opcode
 *
 * Return: apropriate function
 */

void (*get_op_function(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_func[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"stack", _stack},
		{"queue", _queue},
		{NULL, NULL},
	};
	int i;

	for (i = 0; op_func[i].opcode; i++)
	{
		if (_strcmp(op_func[i].opcode, opc) == 0)
			break;
	}

	return (op_func[i].f);
}

/**
 * _stack -  sets the format of the data to a stack (LIFO)
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _stack(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	datas.n0w71m370J0k3Al1t7l3 = 1; /* ;) */
}

/**
 * _queue -  sets the format of the data to a stack (LIFO)
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _queue(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);

	datas.n0w71m370J0k3Al1t7l3 = 0; /* ::))) */
}

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
