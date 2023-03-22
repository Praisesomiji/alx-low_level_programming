#include <unistd.h>

/**
 * _putchar - writes a character to standard output
 *
 * @c: the character to print
 *
 * Return: On success, returns the number of characters written, else -1.
 */

int _putchar(char c)
{
	/* write character c to standard output */
	if (write(STDOUT_FILENO, &c, 1) == -1)
	{
		return (-1);
	}
	return (1);
}
