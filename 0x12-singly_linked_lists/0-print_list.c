#include "lists.h"

/**
 * print_list - prints all the elements of list_t list
 * @h: an pointer to a list_t list
 *
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	int count = 0;
	const list_t *this = h;

	while (this != NULL)
	{
		count++;
		printf("[%d], %s\n", this->len, this->str);
		this = this->next;
	}
	return (count);
}
