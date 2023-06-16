#include <stdio.h>
#include <stdlib.h>

char *_memcpy(char *dest, char *src, unsigned int n);

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
	unsigned int size;

	if (new_size == old_size)
	{
		return (ptr);
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

	if (old_size > new_size)
	{
		size = new_size;
	}
	else
	{
		size = old_size;
	}
	nptr = _memcpy(ptr, nptr, size);
	free(ptr);

	return (nptr);
}

/**
 * _memcpy - copy memory
 * @dest: destination memory
 * @src: source memory
 * @n: number of bytes
 *
 * Return: pointer to destination memory
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
