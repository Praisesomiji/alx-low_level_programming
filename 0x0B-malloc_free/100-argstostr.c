#include <stdio.h>
#include <stdlib.h>

int _strlen(char *str);

/**
* argstostr - concatenate program args
 * @ac: args count
 * @av: args vector
 *
 * Return: concatenated string.
 */
char *argstostr(int ac, char **av)
{
	int len, i, k, l, j;
	char *str;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	len = 0;
	for (i = 0; i < ac; i++)
	{
		len += _strlen(av[i]) + 1;
	}

	str = malloc(sizeof(char) * len);
	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0, k = 0; i < ac; i++, k++)
	{
		l = _strlen(av[i]);

		for (j = 0; j < l; j++, k++)
		{
			*(str + k) = av[i][j];
		}
		*(str + k) = '\n';
	}

	return (str);
}

/**
 * _strlen - find the length of a string
 * @str: a string
 *
 * Return: length of string.
 */
int _strlen(char *str)
{
	int len;

	if (str == NULL)
	{
		return (0);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}
