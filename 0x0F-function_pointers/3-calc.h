#ifndef _3_CALC_H_
#define _3_CALC_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
} op_t;
int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
/**
 * typedef op_funcptr - a pointer to a function
 * @int: int
 *
 * Description: that takes 2 int and returns an int.
 */
typedef int (*op_funcptr)(int, int);
op_funcptr get_op_func(char *s);

#endif /* _3_CALC_H_ */
