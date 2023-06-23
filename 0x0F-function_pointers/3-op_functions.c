#include "3-calc.h"

/**
 * op_add - find the sum of two numbers
 * @a: a number
 * @b: a number
 *
 * Return: Sum.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - find the difference between two numbers
 * @a: a number
 * @b: a number
 *
 * Return: Difference.
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - find the product of two numbers
 * @a: a number
 * @b: a number
 *
 * Return: Product.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - find the quotient of two numbers
 * @a: a number
 * @b: a number
 *
 * Return: Quotient.
 */
int op_div(int a, int b)
{
	if (a == 0 || b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - find the mod of two numbers
 * @a: a number
 * @b: a number
 *
 * Return: Modulus.
 */
int op_mod(int a, int b)
{
	if (a == 0 || b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
