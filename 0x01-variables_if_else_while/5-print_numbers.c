#include <stdio.h>

/**
 * main - A program that prints all single digit numbers of base 10 starting from 0, followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	
	/* Print all single digit numbers of base 10 */
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}

	return (0);
}
