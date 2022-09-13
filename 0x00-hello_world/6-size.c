#include <stdio.h>
/**
 * main - Entry point
 *
 * Print sizes of c data types
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	fprintf(stderr, "Size of a char: %lu byte(s)\n", sizeof(char));
	fprintf(stderr, "Size of a int: %lu byte(s)\n", sizeof(int));
	fprintf(stderr, "Size of a long int: %lu byte(s)\n", sizeof(long int));
	fprintf(stderr, "Size of a long long int: %lu byte(s)\n", sizeof(long long int));
	fprintf(stderr, "Size of a float: %lu byte(s)\n", sizeof(float));

	return (0);
}
