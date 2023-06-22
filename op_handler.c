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
