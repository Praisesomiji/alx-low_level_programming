#include "main.h"
#include <stdio.h>
/**
 * puts2 - print every other char of a string, starting with the first  char.
 * @s: a string
 *
 * Return: nothing.
 */
void puts2(char *str)
{
	int len;
	int i;

	len = 0;

	while (*(str + len))
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		if (!(i % 2)) 
		{
			_putchar(str[i]);
		}
	}
	_putchar('\n');
}
