#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - calculate and allocate memory
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: a pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int n;

	n = nmemb * size;
	ptr = malloc(n);
	if (ptr == NULL)
	{
		exit(98);
	}

	memset(ptr, 0, n);
	return (ptr);
}

