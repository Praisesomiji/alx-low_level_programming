#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - duplicate string
 * @str - string
 *
 * Return duplicate string.
 */
 char *_strdup(char *str)
{
	char *s;
	int len, i;

	len = 0;
	while (str[len] != '\n')
	{
		len++;
	}
	s = malloc(sizeof(char) * (len + 1));
	


	// allocate memory for array of size [size]
// if error, return NULL

// for each byte allocated, initialize it to char [c]
// return pointer to allocated memory 
}
