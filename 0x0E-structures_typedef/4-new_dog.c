#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

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
	
	d = malloc(sizeof (dog_t));
	if (d == NULL)
		return (NULL);

	(*d).name = name;
	(*d).age = age;
	(*d).owner = owner;

	return (d);
}
