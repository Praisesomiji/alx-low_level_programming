#include "3-calc.h"
#include <string.h>

/**
 * get_op - select the correct function to perform operation
 * @s: the operator
 * 
 * Return: a pointer to the function to perform operation
 */
int (*get_op_func(char *s))(int, int)
{
	int i;
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
	};

	i = 5;
	while (i--)
	{
		if (strcmp(s, ops[i].op) == 0)
			return (ops[i].f);
	}
	return (NULL);
}
