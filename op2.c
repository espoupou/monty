#include "monty.h"

/**
 * _mod - mod the top two elements of the stack
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	if (datas.len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (datas.stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;

	if (n < 0 || n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", n);
}
