#include "variadic_functions"

/**
 * print_numbers - print numbers followed by a newline
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 *
 * Return: Nothing
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	int i;
	var_start ap;

	if (separator != NULL)
	{
		for (i = 0; i < n - 1; i++)
			printf("%d%s", var_arg(ap, int), separator);

		printf("%d\n", var_arg(ap, int));
	}
}
