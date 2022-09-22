#include "main.h"
/**
 * print_rev - prints a string in reverse
 * @s: a string
 *
 * Return: nothing.
 */
void print_rev(char *s)
{
	int l;

	for (l = _strlen(s); ; l--)
	{
		_putchar(*(s + l));
	}
	_putchar('\n');
}
