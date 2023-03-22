#include <stdio.h>

/**
 * main - Entry point
 *
 * Description:	Prints all possible combinations of two two-digit numbers
 *		The numbers range from 0 to 99, and are printed with two digits
 *		Combinations of numbers are separated by comma and space, and
 *		are printed in ascending order, and
 *		the combination of numbers 00 01 is considered the same as 01 00
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int tens_1, ones_1, tens_2, ones_2;

	for (tens_1 = 0; tens_1 < 10; tens_1++)
	{
		for (ones_1 = 0; ones_1 < 10; ones_1++)
		{
			for (tens_2 = tens_1; tens_2 < 10; tens_2++)
			{
				int start = (tens_1 == tens_2) ? ones_1 + 1 : 0;

				for (ones_2 = start; ones_2 < 10; ones_2++)
				{
					putchar(tens_1 + '0');
					putchar(ones_1 + '0');
					putchar(' ');
					putchar(tens_2 + '0');
					putchar(ones_2 + '0');

					if (tens_1 != 9 || ones_1 != 8 || tens_2 != 9 || ones_2 != 9)
					{
						putchar(',');
						putchar(' ');
					}
				}
			}
		}
	}

	putchar('\n');

	return (0);
}

