#include "main.h"
#include <stdio.h>

/**
 * _strcat - concatenates two strings.
 * @dest: string
 * @src: string
 *
 * Return: pointer to the resulting string.
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (*(dest + i))
	{
		i++;
	}

	while (*(src + j))
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}

	*(dest + i) = '\0';

	return (dest);
}
