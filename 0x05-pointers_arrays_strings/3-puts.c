#include "main.h"
/**
 * _puts - prints a string
 * @str: a string
 *
 * Return: nothing
 */
void _puts(char *str)
{
	char c;

	for (c=0; *(str + c + 1); c++)
	{
		_putchar(*(str + c));
	}
	_putchar(*(str + c));
	_putchar('\n');
}
