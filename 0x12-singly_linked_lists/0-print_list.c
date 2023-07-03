#include "lists.h"

void printli(const list_t *h, size_t const *n);

/**
 * print_list - prints all the elements of list_t list
 * @h: an pointer to a list_t list
 *
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	size_t const *n = 0;

	if (h != NULL)
		printli(h, ++n);

	return (n);
}

/**
 * printli - prints all the elements of list_t list
 * @h: an pointer to a list_t list
 * @n: keeps track of the number of nodes traversed
 *
 * Return: The number of nodes.
 */
void printli(const list_t *h, size_t const *n)
{
	printf("[%u], %s\n", h->len, h->str);

	if (h->next != NULL)
		printli(h->next, ++n);
}
