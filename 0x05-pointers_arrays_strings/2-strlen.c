#include <stdio.h>
/**
 * _strlen - returns the length of a string
 * @s: a string
 *
 * Return: always an integer
 */
int _strlen(char *s)
{
	int l = 0;
	
	/* while string  */
	while (*(s + l))
	{
		l++;
	}
	return l;
}
