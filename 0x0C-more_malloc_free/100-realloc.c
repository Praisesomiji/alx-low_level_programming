#include <stdio.h>
#include <stdlib.h>

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
	int i;
	void *nptr;

	// if new size is old size: return ptr
	if (new_size == old_size)
	{
		if (ptr != NULL)
		{
			return (ptr);
		}

	}
	// if new size zero: free ptr; return NULL
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
	// if ptr is NULL: return after manually allocating new size
	if (ptr == NULL)
	{
		return (nptr);
	}
	 // if new size is gt old size: added memory shouldnt be initzed
	for (i = 0; i < old_size || i < new_size; i++)
	{
		nptr[i] = ptr[i];
	}
}
