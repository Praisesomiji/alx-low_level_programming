#include "variadic_functions.h"

char *separator(int i);

/**
 * funcptr - pointer to a function
 *
 * Description: A pointer to a function that takes an int and returns a string.
 */
typedef char *(*funcptr)(int);

/**
 * print_all - print all variadic args
 * @format: list of arguments' types
 *
 * Return: Nothing.
 */
void print_all(const char * const format, ...)
{
	int i;
	char *str;
	funcptr sep;
	va_list ap;

	i = 0;
	sep = separator;
	va_start(ap, format);

	if (format != NULL)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sep(i), va_arg(ap, int));
					break;
				case 'i':
					printf("%s%i", sep(i), va_arg(ap, int));
					break;
				case 'f':
					printf("%s%f", sep(i), va_arg(ap, double));
					break;
				case 's':
					str = va_arg(ap, char *);
					if (str != NULL)
					{
						printf("%s%s", sep(i), str);
						break;
					}
					printf("(nil)");
					break;
			}
			i++;
		}
		printf("\n");
	}
}

/**
 * separator - separates string
 * @i: boolean
 *
 * Return: Separator.
 */
char *separator(int i)
{
	if (i == 0)
		return ("");
	return (", ");
}
