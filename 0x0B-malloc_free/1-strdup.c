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

	if (str == NULL)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\n')
	{
		len++;
	}
	
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
        {
                return (NULL);
        }

	for (i = 0; i < len + 1; i++)
	{
		s[i] = str[i];
	} 

	return (s);
}
