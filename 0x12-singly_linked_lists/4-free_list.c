#include "lists.h"

/**
 * free-list - free list_t list
 * @head: first node 
 *
 * Return: Nothing.
 */
void free_list(list_t *head)
{
	list_t = *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
