#include "main.h"
#include <stdio.h>
/**
 * rev_string - reverses a string
 * @s: a string
 *
 * Return: nothing.
 */
void rev_string(char *s)
{
	int l;
	int i;
	int j;
	char r;

	l = 0;

	while (*(s + l))
	{
		l++;
	}

	j = l - 1;

	for (i = 0; i < l / 2; i++)
	{
		r = s[i];
		s[i] = s[j];
		s[j] = r;
		j--;
	}
}
