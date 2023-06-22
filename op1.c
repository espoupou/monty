#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _add(stack_t **stack, unsigned int line_number)
{
	if (datas.len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _nop - do nothing
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
