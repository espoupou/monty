#include "monty.h"

/**
 * _memcpy - fills memory with a constant byte
 * @dest: destination memory aeria pointer
 * @src: source memory aeria pointer
 * @n: number of byte
 * Return: pointer to dest
 */

char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = *(src + i);
	}

	return (dest);
}
