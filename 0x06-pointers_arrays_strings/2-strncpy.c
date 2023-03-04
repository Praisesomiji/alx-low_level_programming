#include "main.h"
#include <stdio.h>

/**
 * _strncpy - conpies a string.
 * @dest: string
 * @src: string
 * @n: integer
 *
 * Return: pointer to the resulting string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (j < n)
	{
		*(dest + i) = *(src + j);
		i++;
		j++;

		if (!(*(src + j)))
			*(dest + i) = '\0';
	}

	return (dest);
}
