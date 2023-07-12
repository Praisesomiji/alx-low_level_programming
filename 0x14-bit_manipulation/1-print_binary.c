#include "main.h"

unsigned long int printbchar(unsigned long int n);

/**
 * print_binary - prints the binary representation of a number
 * @n: a number
 *
 * Return: Nothing.
 */
void print_binary(unsigned long int n)
{
	while (n)
	{
		n = printbchar(n);
	}
	printbchar(n);
}
/**
 * printbchar - divide a number by 2, print remainder and return quotient
 * @n: a number
 *
 * Return: Quotient of the number and 2.
 */
unsigned long int printbchar(unsigned long int n)
{
	unsigned long int m = n;

	m >>= 1;
	if (n != (m * 2))
		_putchar('0');
	else
		_putchar('1');
	return (m);
}
