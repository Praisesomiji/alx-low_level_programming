#include "main.h"
#include <stdlib.h> /* For the system() function */

int main(void)
{
	int status;

	/* Compile the C file using gcc */
	status = system("gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 0-putchar.c -o 0-putchar");
	status = system("gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 1-main.c 1-alphabet.c -o 1-alphabet");
	status = system("gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 2-main.c 2-print_alphabet_x10.c -o 2-alphabet_x10")


	/* Check if the compilation was successful */
	if (status == 0)
	{
		/* Compilation was successful */
		printf("Compilation successful\n");
	}
	else
	{
	/* Compilation failed */
	printf("Compilation failed\n");
	}

	return (0);
}
