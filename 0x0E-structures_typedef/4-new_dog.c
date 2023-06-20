#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

int _storcpy(char *dest, char *src);

/**
 * new_dog - create new dog
 * @name: name
 * @age: age
 * @owner: owner
 *
 * Return: dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	_storcpy((*d).name, name);
	_storcpy((*d).owner, owner);

	(*d).age = age;

	return (d);
}

/**
 * _storcpy - store a copy off src in dest
 * @dest: destination string
 * @src: source string
 *
 * Return: Success(0).
 */
int _storcpy(char *dest, char *src)
{
	int i, len;

	if (src == NULL)
		return (98);

	for (len = 1; src[len] != '\0'; len++)
		;
	dest = malloc(sizeof(*src) * len);
	if (dest == NULL)
		return (98);

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	return (0);
}
