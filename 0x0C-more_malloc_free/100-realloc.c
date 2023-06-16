#include <stdio.h>
#include <stdlib.h>

void *popalloc(char *ptr, char *nptr, unsigned int os, unsigned int ns);

/**
 * _realloc - reallocate memory block
 * @ptr: pointer to memory
 * @old_size: old size of memory
 * @new_size: new size of memory
 *
 * Return: pointer to memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (new_size == old_size)
	{
		if (ptr != NULL)
		{
			return (ptr);
		}

	}

	if (new_size == 0)
	{
		if (ptr != NULL)
		{
			free(ptr);
		}
		return (NULL);
	}

	nptr = malloc(new_size);
	if (nptr == NULL)
	{
		return (NULL);
	}

	if (ptr == NULL)
	{
		return (nptr);
	}

	nptr = popalloc(ptr, nptr, old_size, new_size);
	return (nptr);
}

/**
 * popalloc - populate reallocated memory
 * @ptr: old pointer
 * @nptr: new pointer
 * @os: old size
 * @ns: new size
 *
 * Return: new pointer
 */
void *popalloc(char *ptr, char *nptr, unsigned int os, unsigned int ns)
{
	unsigned int i;

	for (i = 0; i < os || i < ns; i++)
	{
		nptr[i] = ptr[i];
	}
	return (nptr);
}
