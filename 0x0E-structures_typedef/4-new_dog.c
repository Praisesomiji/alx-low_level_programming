#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *str);

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
	int l0, l1;

	if (name == NULL || owner == NULL)
		exit(98);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		exit(98);

	l0 = _strlen(name);
	d->name = malloc(sizeof(char) * (l0 + 1));
	if (d->name == NULL)
		exit(98);

	l1 = _strlen(owner);
	d->owner = malloc(sizeof(char) * (l1 + 1));
	if (d->owner == NULL)
		exit(98);

	if (_strncpy(d->name, name, l0) == NULL)
		exit(98);

	if (_strncpy(d->owner, owner, l1) == NULL)
		exit(98);

	d->age = age;

	return (d);
}

/**
 * _strlen - find length of string
 * @str: string
 *
 * Return: lenght of string.
 */
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;
	return (len);
}

/**
 * _strncpy - store a copy off src in dest
 * @dest: destination string
 * @src: source string
 * @n: number of chars to be copied
 *
 * Return: Success(0).
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
