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
	{
		fprintf(stderr, "Error: malloc failed\n");
		_free_datas();
		exit(EXIT_FAILURE);
	}

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
		printf("%d\n", p->n);
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
	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: the stack adress
 * @line_number: the line number
 * Return: Nothing
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	if (datas.stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	delete_dnodeint_at_index(stack, 0);
	datas.len--;
}

/**
 * _swap - waps the top two elements of the stack
 * @stack: the stack adress
 * @line_number: the line number
 * Return: Nothing
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	int n;

	if (datas.len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		_free_datas();
		exit(EXIT_FAILURE);
	}

	n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = n;
}
