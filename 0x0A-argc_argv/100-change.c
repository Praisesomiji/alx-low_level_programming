#include <stdio.h>
#include <stdlib.h>

int calcdenom(int, int);

/**
 * main - prints the minimum number of coins.
 * @argc: command line args count
 * @argv: array of command line args
 *
 * Return: success(0).
 */

int main(int argc, char *argv[])
{
	int cents;
	int dcoins;
	int i;
	int denom[5] = { 25, 10, 5, 2, 1 };
	long coins = 0;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("%i\n", 0);
		return (0);
	}

	for (i = 0; i < 5; i++)
	{
		dcoins = calcdenom(cents, denom[i]);
		coins += dcoins;
		cents -= dcoins * denom[i];
	}

	printf("%ld\n", coins);
	return (0);
}

/**
 * calcdenom - calc how many pieces of this denom
 * can be gotten from n.
 * @cents: cents
 * @denom: denomination
 *
 * Return: answer.
 */

int calcdenom(int cents, int denom)
{
	if (cents > denom - 1)
	{
		return (cents / denom);
	}
	else
	{
		return (0);
	}
}
