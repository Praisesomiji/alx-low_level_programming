#include <stdio.h>
#include <stdlib.h>

/**
 * malloc_checked - allocate memory
 * @b: size of memory
 *
 * Returns: a pointer to the allocated memory.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (!ptr)
	{
		exit(EXIT_FAILURE);
	}
	return ptr;
}
