#include "lists.h"

/**
 * print_list - returns the number of elements in a linked list
 * @h: head of linked list
 *
 * Return: The number of nodes in the linked list.
 */
size_t print_list(const list_t *h)
{
	int count = 0;
	const list_t *this = h;

	while (this != NULL)
	{
		printf("[%u] %s\n", this->len, this->str);
		count++;
		this = this->next;
	}
	return (count);
}
