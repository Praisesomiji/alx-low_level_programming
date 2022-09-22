#include "main.h"
/**
 * _puts - prints a string
 * @str: a string
 *
 * Return: nothing
 */
void _puts(char *str)
{
	int l;

	for (l = 0; *(str + l); l++)
	{
		_putchar(*(str + l));
	}
	_putchar('\n');
}
