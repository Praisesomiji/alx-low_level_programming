#include "main.h"

int getbitindex(unsigned long int n, unsigned int index, unsigned int i);

/**
 * get_bit -  get the value of a bit at a given index
 * @n: a number
 * @index: index to find in base 2 of given number
 *
 * Return: returns the value of the index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int output;

	output = getbitindex(n, index, 0);

	return (output);
}
/**
 * getbitindex - get the value at given index of a binary number
 * @n: a number
 * @index: index of value to print
 * @i: index to traverse number
 *
 * Return: the value of the bit at index index or -1 if an error occured.
 */
int getbitindex(unsigned long int n, unsigned int index, unsigned int i)
{
	unsigned long int m;
	unsigned int q, allowance;
	int result;

	/* Divide number by 2 */
	m = n >> 1;
	/* If this is the index of the value to get */
	if (index == i)
	{
		/* Return the mod of the number and 2 */
		if (n != (m * 2))
			return (1);
		else
			return (0);
	}
	/* If the quotient of the number and 2 is not 0 */
	if (m != 0)
	{
		result = getbitindex(m, index, i + 1);
		if (result >= 0)
			return (result);
	}

	/*
	 * At this point,
	 * n is either 0 or 1,
	 * i is not index,
	 * i is not 0
	 */
	q = i >> 2;
	allowance = (4 * (q + 1)) - i;
	if (index < allowance)
		return (0);
	return (-1);
}
