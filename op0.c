#include "monty.h"

/**
 * _push - push to stack
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	int n;

	if (datas.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	for (n = 0; datas.arg[n] != '\0'; n++)
	{
		if (!isdigit(datas.arg[n]) && datas.arg[n] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			_free_datas();
			exit(EXIT_FAILURE);
		}
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_handler(6);

	n = atoi(datas.arg);
	/**
	 *	new->n = n;
	 *	new->next = stack;
	 *	new->prev = NULL;
	 *	if (stack != NULL)
	 *	stack->prev = new;
	 * datas.len++;
	 * stack = new;
	 */

	add_dnodeint(stack, n);
	datas.len++;
}

/**
 * _pall - print all element in the stack
 * @stack: the stack adress
 * @line_number: the line number
 * Return: nothing
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p = *stack;

	UNUSED(line_number);

	while (p != NULL)
	{
		fprintf(stdout, "%d\n", p->n);
		p = p->next;
	}
}

/**
 * _pint - print first element ont he statck
 * @stack: the stack adress
 * @line_number: the line number
 * Return: Nothing
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (datas.stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
