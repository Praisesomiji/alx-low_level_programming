#include <stdio.h>

/**
 * main - returns the name of this program.
 * @argc: command line args count
 * @argv: array of command line args
 *
 * Return: nothing.
 */

int main(int argc, char* argv[])
{
	printf("%s\n", argv[argc - argc]);
	return (0);
}
