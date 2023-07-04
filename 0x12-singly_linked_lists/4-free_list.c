#include "lists.h"

/**
 * free_list - free list_t list
 * @head: first node
 *
 * Return: Nothing.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		if (temp-> str)
			free(temp->str);
		free(temp);
	}
}
