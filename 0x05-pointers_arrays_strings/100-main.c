#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Description: This is the main function that runs the program.
 * It tests the _atoi function by passing it various string arguments.
 *
 * Return: Always 0.
 */

int main(void)
{
	int nb;
	{
		nb = _atoi("98");
	}
	printf("%d\n", nb);
	nb = _atoi("-402");
	printf("%d\n", nb);
	nb = _atoi("          ------++++++-----+++++--98");
	printf("%d\n", nb);
	nb = _atoi("214748364");
	printf("%d\n", nb);
	nb = _atoi("0");
	printf("%d\n", nb);
	nb = _atoi("Suite 402");
	printf("%d\n", nb);
	nb = _atoi("         ++--98 Battery Street; San Francisco, CA 94111 - USA");
	printf("%d\n", nb);
	nb = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");
	printf("%d\n", nb);

	return (0);
}
