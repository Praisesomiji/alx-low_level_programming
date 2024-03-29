#include "lists.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h: head of linked list
 *
 * Return: The number of elements in the linked list.
 */
size_t list_len(const list_t *h)
{
	int count = 0;
	const list_t *this = h;

	while (this != NULL)
	{
		count++;
		this = this->next;
	}
	return (count);
}
