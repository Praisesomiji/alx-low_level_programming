#include "main.h"
/**
 * _puts(char *str);
 * @str: a string
 *
 * Return: nothing
 */
void _puts(char *str)
{
	char c = 0;

	while (*(str + c))
	{
		_putchar(*(str + c));
		c++;
	}
	_putchar('\n');
}
