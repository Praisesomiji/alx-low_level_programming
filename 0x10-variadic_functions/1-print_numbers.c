#include "variadic_functions.h"

/**
 * print_numbers - print numbers followed by a newline
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 *
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;

	va_start(ap, n);
	if (separator != NULL)
	{
		for (i = 0; i < n - 1; i++)
			printf("%d%s", va_arg(ap, int), separator);

		printf("%d\n", va_arg(ap, int));
	}
	va_end(ap);
}
