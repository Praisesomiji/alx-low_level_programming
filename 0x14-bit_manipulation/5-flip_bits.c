#include "main.h"

int getmod(unsigned long int whole, unsigned long int half);

/**
 * flip_bits - find the number of bits to be flipped to get from one number to another
 * @n: a number
 * @m: another number
 *
 * Return: the number of bits that would need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int flips;
	unsigned long int temp;
	int a, b;

	/*
	 * n 24 - a 1 1 0 0 0
	 * m 15 - b 0 1 1 1 1
	 * d  9 - c 0 1 0 0 1 
	 * Divide n and m by 2 silmulteaneously
	 * For every stage of division with varying remainders:
	 *	count it for flips
	 * When a quotient becomes 0:
	 *	mark it as 0 as long as the loop continues
	 *When both quotient becomes 0:
	 *	end loop
	 * return flips
	 */
	flips = 0;
	while (n || m)
	{
		if (n)
		{
			temp = n;
			n =>> 1;
			a = getmod(temp, n);
		}
		else
		{
			if (a)
				a = 0;
		}

		if (m)
		{
			temp = m;
			m =>> 1;
			b = getmod(temp, m);
		}
		else
		{
			if (b)
				b = 0;
		}

		if (a != b)
			flips++;
	}
	return (flips);
}
/** 
 * getmod - get the mod of 2 and a whole number 
 * @whole: a whole number
 * @half: half of the whole or of the whole - 1
 *
 * Return: 0 if whole is even, else 1.
 */
int getmod(unsigned long int whole, unsigned long int half)
{
	if ((half * 2) == whole)
		return (0);
	else
		return (1);
}
