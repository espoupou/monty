
#include "monty.h"

/**
 * _charchk - compare chars of strings
 * @str: input string.
 * @delim: delimiter.
 * Return: 1 if are equals, 0 if not.
 */
int _charchk(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strcmp - compare two string
 * @s1: first string
 * @s2: the second string
 * Return: -1 0 or 1
 */

int _strcmp(char *s1, char *s2)
{
	char *p = s1, *q = s2;

	while (*p == *q && *p)
	{
		p++;
		q++;
	}

	if (*p > *q)
		return (1);
	if (*p < *q)
		return (-1);
	return (0);
}
