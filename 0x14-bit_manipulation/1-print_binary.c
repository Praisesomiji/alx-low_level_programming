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
	unsigned long int m;

	m = n >> 1;
	if (m != 0)
		printbchar(m);

	if (n != (m * 2))
		_putchar('1');
	else
		_putchar('0');

	return (m);
}
