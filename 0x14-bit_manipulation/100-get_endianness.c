#include "main.h"

/**
 * get_endianness - checks the endianness
 *
 * Return: 0 if big endian, 1 if little indian.
 */
int get_endianness(void)
{
	unsigned int n;
	unsigned char *np;

	/* Convert p to int to p to char to access a byte at a time */
	n = 0x0A0B0C0D;
	np = (unsigned char *)&n;
	/* Big endian if the most significant byte is stored first */
	if (*np == 0x0A)
		return (0);
	/* Little endian, most significant stored last */
	return (1);
}
