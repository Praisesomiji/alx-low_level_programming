#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index.
 * @n: pointer to a number
 * @index: index of the value in n to be reset
 * Return: 1 if it worked or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	int output;
	unsigned long int d;

	output = get_bit(&n, index);

	if (output == -1)
		return (-1);

	if (output == 0)
		(*n) += _raiseto(2, index);

	return (1);
}
