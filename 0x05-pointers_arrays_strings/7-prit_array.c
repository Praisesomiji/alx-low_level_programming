#include "main.h"
#include <stdio.h>
/**
 * puts_half - print the second half of a string.
 * @str: a string
 *
 * Return: nothing
 */
void puts_half(char *str)
{
	int len;
	int n;
	int div;

	len = 0;
	while (*(str + len))
	{
		len++;
	}

	div = 2;
	n = len / div;

	if (len % 2)
		n = n + 1;

	while (len > n)
	{
		_putchar(str[n]);
		n++;
	}

	_putchar('\n');
}
