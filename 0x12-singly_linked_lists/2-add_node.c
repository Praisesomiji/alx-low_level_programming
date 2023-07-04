#include "lists.h"
#include <string.h>

unsigned int _strlen(char *str);

/**
 * add_node - adds a new node at the beginning of a list
 * @head: pointer to a linked list
 * @str: string to add as data in new node
 *
 * Return: The address of the new element, or NULL if it failed.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *this;
	list_t *new;
	char *data;

	if (head == NULL)
		return (NULL);

	this = *head;
	data = strdup(str);
	if (data == NULL)
		return (NULL);

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->str = data;
	new->len = _strlen(data);
	if (this != NULL)
		new->next = this;
	else
		new->next = NULL;
	
	*head = new;
	return (new);
}

/**
 * _strlen - return the length of a string
 * @str: a string
 *
 * Return: The length of a string.
 */
unsigned int _strlen(char *str)
{
	unsigned int len = 0;

	if (str != NULL)
	{
		while(*str)
		{
			len++;
			str++;
		}
	}
	return (len);
		
}
