#include "main.h"
#include <stdio.h>
/**
 * print_rev - prints a string in reverse
 * @s: a string
 *
 * Return: nothing.
 */
void print_rev(char *s)
{
	int l = 0;

        while (*(s + l))
        {
                l++;
        }
	
	for (; l >= 0; l--)
	{
		_putchar(*(s + l));
	}
	_putchar('\n');
}
