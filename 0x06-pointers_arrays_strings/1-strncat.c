#include "main.h"
#include <stdio.h>

/**
 * _strncat - concatenates two strings.
 * @dest: string
 * @src: string
 * @n: integer
 *
 * Return: pointer to the resulting string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (*(dest + i))
	{
		i++;
	}

	while (j < n)
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
		
		if (!(*(src + j)))
		{
			*(dest + i) = '\0';
			break;
		}
	}

	return dest;
}
