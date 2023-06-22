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
