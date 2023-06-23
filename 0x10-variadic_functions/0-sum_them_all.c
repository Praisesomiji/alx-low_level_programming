#include "variadic_functions.h"

int sum_them_all(const unsigned int n, ...)
{
	int sum, i;
	va_list ap;

	if (n == 0)
		return (0);

	va_start(ap, n);
	sum = 0;
	for (i = n; i != 0; i = va_arg(ap, int))
		sum += i;
	va_end(ap);`
}
