#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <stddef.h>

long int stol(char *s);
void quit(int b);

/**
 * main - multiples two positive numbers
 * ac: number of arguments
 * av: array of arguments
 *
 * Return: status.
 */
int main(int ac, char **av)
{
	long int num1, num2;

	quit(ac < 3);

	num1 = stol(av[1]);
	num2 = stol(av[2]);

	printf("%ld\n", num1 * num2);
	return (0);
}

/**
 * stol - convert string to long int
 * @s: string digit
 *
 * Return: converted digit.
 */
long int stol(char *s)
{
	long int n;
	char *ptr;

	errno = 0;
	n = strtol(s, &ptr, 10);

	quit((errno == ERANGE && (n == LONG_MAX || n == LONG_MIN)));
	quit(errno != 0 && n == 0);
	quit(ptr == s);
	quit(*ptr != '\0');

	return (n);
}

/**
 * quit - print error and exit
 * @b: to exit or not to exit
 *
 * Return: Nothing.
 */
void quit(int b)
{
	if (b)
	{
		printf("Error\n");
		exit(98);
	}
}
