#include <stdio.h>
#include <stdlib.h>

int _strlen(char *str);

/**
 * string_nconcat - concatenate two strings
 * @s1: a string
 * @s2: a string
 * @n: number of chars to copy from second string
 *
 * Return: pointer to allocated space in memory
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int size, i, j;
	unsigned int l1, l2;
	char *str;

	l1 = _strlen(s1);
	l2 = _strlen(s2);

	if (n >= l2)
	{
		size = l1 + l2;
	}
	else
	{
		size = l1 + n;
	}

	str = malloc(sizeof(*str) * size + 1);
	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < l1; i++)
	{
		str[i] = s1[i];
	}
	for (j = 0; i < size; i++, j++)
	{
		str[i] = s2[j];
	}
	str[i] = '\0';

	return (str);
}

/**
 * _strlen - find the length of a string
 * @str: a string
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len;

	len = 0;
	if (str != NULL)
	{
		while (str[len] != '\0')
		{
			len++;
		}
	}
	return (len);
}

