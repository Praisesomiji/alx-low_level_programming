#include <stdio.h>
#include <stdlib.h>

void *_memset(char *ptr, char b, unsigned int n);

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
		return (NULL);
	}

	_memset(ptr, 0, n);
	return (ptr);
}

/**
 * _memset - set all the bytes in memory to a given value
 * @ptr: address of the memory
 * @b: value to set the memory to
 * @n: number of bytes to set
 *
 * Return: a pointer to the set memory.
 */
void *_memset(char *ptr, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		ptr[i] = b;
	}
	return (ptr);
}
