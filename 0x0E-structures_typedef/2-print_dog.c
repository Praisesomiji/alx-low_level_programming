#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

void print_element(char *desc, char *props, float *propf)

/**
 * print_dog - print the properties of given dog
 * @dog: address of the dog
 *
 * Return: Nothing
 */
void print_dog(struct dog *d)
{
	if (d != NULL)
	{
		print_element("Name", d->name, NULL);
		print_element("Age", NULL, &d->age);
		print_element("Owner", d->owner, NULL);
	}
}

/**
 * print_prop - print a given property of a given struct
 * desc: description of property
 * prop: property
 */
void print_element(char *desc, char *props, float *propf)
{
	if (props == NULL)
	{
		if (propf == NULL)
		{
			propf = "nil";
		}
		printf("%s: %f\n", *desc, *propf);
	}
	printf("%s: %s\n", *desc, *props);
}
