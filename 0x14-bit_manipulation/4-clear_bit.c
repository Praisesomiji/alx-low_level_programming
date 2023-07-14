#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index.
 * @n: pointer to a number
 * @index: index, starting from 0 of the bit you want to set
 * Return: 1 if it worked or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	int output;

	output = get_bit(*n, index);

	if (output == -1)
		return (-1);

	if (output == 1)
		(*n) -= _raiseto(2, index);

	return (1);
}
/**
 * _raiseto - raise a number to the power of another number
 * @d: a digit to be raised
 * @r: the power to raise a number to
 *
 * Return: the exponent.
 */
unsigned int _raiseto(unsigned int d, unsigned int r)
{
	switch (r)
	{
		case 0:
			d = 1;
			break;
		case 1:
			break;
		default:
			d <<= (r - 1);
			break;
	}
	return (d);
}
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
	unsigned int q, wordlen, allowance;
	int result;

	m = n >> 1;
	if (index == i)
	{
		if (n != (m * 2))
			return (1);
		else
			return (0);
	}
	if (m != 0)
	{
		result = getbitindex(m, index, i + 1);
		if (result >= 0)
			return (result);
	}
	wordlen = sizeof(n) * 8;
	q = i >> (wordlen >> 1);
	allowance = (wordlen * (q + 1)) - i;
	if (index < allowance)
		return (0);
	return (-1);
}
