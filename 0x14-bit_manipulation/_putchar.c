#include <unistd.h>

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
