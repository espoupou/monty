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

	_free_datas();
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
