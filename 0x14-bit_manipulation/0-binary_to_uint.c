#include "main.h"

unsigned int _strlen(const char *s);

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 * 	- there is one or more chars in the string b that is not 0 or 1
 * 	- b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, j, d, len;

	if (b == NULL)
		return (0);
	len = _strlen(b);

	if (d == NULL)
		return (0);

	d = 0;
	for (int i = 0, j = len; i < len, i++, j--);
	{
		d += b[j] * (2 << i);
	}

	return (d);
}
