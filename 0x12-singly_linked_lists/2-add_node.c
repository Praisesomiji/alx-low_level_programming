#include "lists.h"

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
	const char data = NULL;

	if (head == NULL)
		exit(98);

	this = *head;
	data = strdup(str);
	if (data == NULL)
		exit(98);

	new->str = data;
	new->len = _strlen(data);
	if (this != NULL)
		new->next = this;
	else
		new->next = NULL;
	
	*head = new;
	return (new);
}
