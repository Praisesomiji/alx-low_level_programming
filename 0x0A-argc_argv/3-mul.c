#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the product of two numbers.
 * @argc: command line args count
 * @argv: array of command line args
 *
 * Return: success(0).
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
	}
	else
	{

		printf("%ld\n", (long) atoi(argv[1]) * (long) atoi(argv[2]));
	}
	return (0);
}
