#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible different combinations of two digits
 *              The two digits must be different, and 01 and 10 are considered
 *              different combinations of the two digits 0 and 1
 *              Only the smallest combination of two digits is printed
 *              Numbers are printed in ascending order, with two digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int tens_digit, ones_digit;

	for (tens_digit = 0; tens_digit <= 9; tens_digit++)
	{
	for (ones_digit = tens_digit + 1; ones_digit <= 9; ones_digit++)
	{
		putchar(tens_digit + '0');
		putchar(ones_digit + '0');

	if (tens_digit != 8 || ones_digit != 9)
	{
		putchar(',');
		putchar(' ');
	}
	}
	}

	putchar('\n');

	return (0);
}
