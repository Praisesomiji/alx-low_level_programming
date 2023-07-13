#include "main.h"

int getbitindex(unsigned long int n, unsigned int index,
unsigned int *const pindex);

/**
 * get_bit -  get the value of a bit at a given index
 * @n: a number
 * @index: index to find in base 2 of given number
 *
 * Return: returns the value of the index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i = 0;
	int output;

	output = getbitindex(n, index, &i);

	return (output);
}
/**
 * getbitindex - get the value at given index of a binary number
 * @n: a number
 * @index: index of value to print
 * @pindex: pointer to index
 *
 * Return: the value of the bit at index index or -1 if an error occured.
 */
int getbitindex(unsigned long int n, unsigned int index,
unsigned int *const pindex)
{
	unsigned long int m;
	int result;

	m = n >> 1;
	if (m != 0)
	{
		result = getbitindex(m, index, pindex);
		if (result >= 0)
			return (result);
	}
	if (index == *pindex)
	{
		if (n != (m * 2))
			return (1);
		else
			return (0);
	}

	(*pindex) += 1;
	return (-1);
}
