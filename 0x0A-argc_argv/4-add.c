#include <stdio.h>
#include <stdlib.h>
#include  <string.h>

int positive(char*, int*);

/**
 * main - prints sum of positive numbers
 * @argc: command line args count
 * @argv: array of command line args
 *
 * Return: success(0) or failure(1).
 */
int main(int argc, char *argv[])
{
	int sum;
	int i;

	for (i = 1, sum = 0; i < argc; i++)
	{
		if (positive(argv[i], &sum) != 0)
		{
			return (1);
		}
	}
	printf("%i\n", sum);

	return (0);
}

/**
 * positive - checks if a given digit is positive
 * @m: given arg
 * @sum: accumulator
 *
 * Return: success(0) or failure(0).
 */
int positive(char *m, int *sum)
{
	int n = atoi(m);

	if (n == 0)
	{
		if (strcmp(m, "0") != 0)
		{
			printf("Error\n");
			return (1);
		}
	}

	(*sum) += n;

	return (0);
}
