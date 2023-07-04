#include "lists.h"

/**
 * print_list - returns the number of elements in a linked list
 * @h: head of linked list
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;
	const list_t *this = h;

	if ((*h) == NULL)
		return (0);

	while (this != NULL)
	{
		printf("[%i] %s\n", this->len, this->str);
		count++;
		this = this->next;
	}
	return (count);
}
