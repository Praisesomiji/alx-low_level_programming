#include <stdio.h>

/**
 * main - prints the number of args passed to its exe
 * @argc: command line args count
 * @argv: array of command line args
 *
 * Return: success(0).
 */

int main(int argc, char *argv[])
{
	if (argv[0] != NULL)
	{
		printf("%i\n", argc - 1);
	}
	return (0);
}
