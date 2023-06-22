#include "monty.h"

/**
 * error_handler - error handler
 * @code: the error code
 * Return: exit the program
 */

void error_handler(int code)
{
	switch (code)
	{
		case 6:
			error_malloc();
			break;
		default:
			return;
	}

	/* data freing */
	exit(EXIT_FAILURE);
}

/**
 * error_malloc - can't malloc anymore error
 * Return: error string
 */

char *error_malloc()
{
	int length;
	char *error;

	length = 21;
	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
		return (NULL);

	_strcpy(error, "Error: malloc failed\n");
	return (error);
}

/**
 * empty_stack_err - empty stack error
 * Return: nothing
 */

void empty_stack_err(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty", datas.line);
}

/**
 * error_open_stream - can't open stream
 *
 * Return: error string
 */

char *error_open_stream()
{
	int length;
	char *error;

	length = 23 + _strlen(datas.file);

	error = malloc(sizeof(char) * (length + 1));
	if (error == NULL)
	{
		return (NULL);
	}
	_strcpy(error, "Error: Can't open file ");
	_strcat(error, datas.file);

	return (error);
}

