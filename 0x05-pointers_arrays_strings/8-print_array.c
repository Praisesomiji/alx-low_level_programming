#include "main.h"
#include <stdio.h>
/**
 * print_array - print n elements of an array of integers, followed by a new line.
 * @a: an array
 * @n: an integer
 *
 * Return: nothing
 */
void print_array(int *a, int n)
{
	int len;
	int i;
	int j;

	len = 0;
	while (*(a + len))
	{
		len++;
	}

	if (n < len)
		j = n;
	else j = len;

	for (i = 0; i < j; i++)
	{
		_putchar(*(a + i));
                _putchar(',');
                _putchar(' ');
        }

	_putchar('\n');
}
