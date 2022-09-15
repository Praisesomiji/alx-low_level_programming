#include "main.h"

/**
 * _print_alphabet_x10 - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _print_alphabet_x10(void)
{
	int i;

	for (i = 1; i <= 10; i++)
	{
		print_alphabet();
	}
	return (0);
}
