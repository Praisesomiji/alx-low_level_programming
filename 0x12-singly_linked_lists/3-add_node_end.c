#include "lists.h"

unsigned int _strlen(char *str);

/**
 * add_node_end - add a new node at the end of a list
 * @head: pointer to a linked list
 * @str: data for a linked list
 *
 * Return: New node.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *this;
	list_t *new;
	char *data;

	if (head == NULL)
		return (NULL);

	data = strdup(str);
	if (str == NULL)
		return (NULL);

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);

	new->str = data;
	new->len = _strlen(data);
	new->next = NULL;

	this = *head;
	if (this != NULL)
		this.next = new;
	else
		this = new;

	return (this);
}
/**
 * _strlen - Calculate string length
 * @str: a string
 *
 * Return: Length of string.
 */
unsigned int _strlen(char *str)
{
	unsigned int count = 0;

	if (str != NULL)
		while (*str)
		{
			count++;
			str++;
		}
	return (count);
}
