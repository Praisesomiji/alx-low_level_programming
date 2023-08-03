#include "main.h"

unsigned int _chartoint(char c);
unsigned int _isbchar(char c);
unsigned int _raiseto(unsigned int d, unsigned int r);
unsigned int _strlen(const char *s);

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 *	- there is one or more chars in the string b that is not 0 or 1
 *	- b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, j, len;
	unsigned int d, n, x;

	if (b == NULL)
		return (0);

	len = _strlen(b);
	d = 0;
	for (i = 0, j = len - 1; i < len; i++, j--)
	{
		n = _chartoint(b[j]);
		x = n * _raiseto(2, i);
		d = d + x;
	}
	return (d);
}
/**
 * _chartoint - convert a char to a digit
 * @c: a char
 *
 * Return: the converted integer.
 */
unsigned int _chartoint(char c)
{
	return (c - 48);
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
 * _strlen - find the length of a binary (string)
 * @s: a string
 *
 * Return: the length of a string, or 0
 *	- the binary string contains a char different from '0' and '1'.
 */
unsigned int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		if (!_isbchar(s[len]))
			return (0);
		len++;
	}
	return (len);
}
/**
 * _isbchar - checks that a char is '0' or '1'
 * @c: a char
 *
 * Return: True (1) if char is binary, else
 *	- False (0);
 */
unsigned int _isbchar(char c)
{
	if (c == '0' || c == '1')
		return (1);
	else
		return (0);
}
