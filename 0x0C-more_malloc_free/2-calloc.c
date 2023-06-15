#include <stdio.h>
#include <stdlib.h>

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
	unsigned int i, c;

	c = a * b;
	ptr = malloc(c);
	if (ptr == NULL)
	{
		exit(98);
	}

	for (i = 0; i < c; i++)
	{
		ptr[i] = 0;
	}
	return (ptr);
}
