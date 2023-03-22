#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints all the numbers of base 16 in lowercase
 * using the putchar function only three times.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char hex_digit = '0';

	while (hex_digit <= 'f')
	{
		if (hex_digit <= '9' || hex_digit >= 'a')
		{
			putchar(hex_digit);
			hex_digit++;
		}
		else
		{
			hex_digit++;
		}
	}

	putchar('\n');

	return (0);
}
