#include <stdio.h>
#include <stdlib.h>

/**
 * create_array - create an array of chars
 * @size: size of the array
 * @c:char to initialize array with
 *
 * Return: array of chars
 */
char *create_array(unsigned int size, char c)
{
	char *s;
	unsigned int i;

	if (size == 0)
	{
		return (NULL);
	}

	s = malloc(sizeof(char) * size);
	if (s == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		s[i] = c;
	}
	return (s);
}
