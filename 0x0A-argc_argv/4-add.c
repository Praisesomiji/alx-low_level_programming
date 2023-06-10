#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prints sum of positive numbers
 * @argc: command line args count
 * @argv: array of command line args
 *
 * Return: success(0).
 */

int main(int argc, char *argv[])
{
	int sum, i;

	for (i = 1, sum = 0; i < argc; i++)
	{
		char *m = argv[i];
		int n = atoi(m);

		if (n == 0 && strcmp(m, "0") != 0)
		{
			printf("Error\n");
			return (1);
		}
		sum += n;
	}
	printf("%i\n", sum);

	return (0);
}
