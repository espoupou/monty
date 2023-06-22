#include "monty.h"

/**
 * error_usage - usage synthax error
 *
 * Return: error string
 */

char *error_usage()
{
	int length;
	char *error;

	length = 17;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		return (NULL);
	}

	_strcpy(error, "USAGE: monty file\n");

	return (error);
}
