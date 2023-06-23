#include "3-calc.h"

/**
 * main - perform simple math operations
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: Nothing.
 */
int main(int ac, char **av)
{
	int result, a, b;
	op_funcptr op_ptr;

	if (ac != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op_ptr = get_op_func(av[2]);
	if (op_ptr == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	a = atoi(av[1]);
	b = atoi(av[3]);
	result = op_ptr(a, b);

	printf("%d\n", result);

	return (0);
}
