#include <stdio.h>
#include <stdlib.h>

int _strlen(char *str);

/**
* str_concat - concatenate two strings
 * @s1: first string
 * @s2: last string
 *
 * Return: concatenate strings.
 */
char *str_concat(char *s1, char *s2)
{
	char *s;
	int l1, l2, l, i;

	l1 = _strlen(s1);
	l2 = _strlen(s2);
	l = l1 + l2;

	s = malloc(sizeof(char) * (l + 1));
	if (s == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < l1 + 1; i++)
	{
		s[i] = s1[i];
	}
	for (; i < l; i++)
	{
		s[i] = s2[i];
	}
	s[i] = '\0';

	return (s);
}

/** 
 * _strlen - find the length of a string
 * @str: a string
 *
 * Return: length of string.
 */
int _strlen(char *str)
{
	int len;

	if (str == NULL)
	{
		return (0);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}
