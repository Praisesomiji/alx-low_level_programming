#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: a number
 *
 * Return: Nothing.
 */
void print_binary(unsigned long int n)
{
	int m;

	while (n)
	{
		n = printbchar(n);
	}
	printbchar(n);
	_putchar('\n');
}
/**
 * _putchar - print a char to te standard output
 * @c: a char
 *
 * Return: On succes 1.
 * On error, -1 is returned, and erno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * printbchar - divide a number by 2, print remainder and return quotient
 * @n: a number
 *
 * Return: Quotient of the number and 2.
 */
unsigned long int printbchar(unsigned long int n)
{
	int m = n;

	m =>> 1;
	if (n != (m * 2))
		_putchar('0');
	else
		_putchar('1');
	return m;
}
