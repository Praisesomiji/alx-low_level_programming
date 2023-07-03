#include "lists.h"

void printli(const list_t *h, size_t *const np);

/**
 * print_list - prints all the elements of list_t list
 * @h: an pointer to a list_t list
 *
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;

	printli(h, &n);

	return (n);
}

/**
 * printli - prints all the elements of list_t list
 * @h: an pointer to a list_t list
 * @np: keeps track of the number of nodes traversed
 *
 * Return: The number of nodes.
 */
void printli(const list_t *h, size_t *const np)
{
	if (h != NULL)
	{
		(*np)++;
		printf("[%u], %s\n", h->len, h->str);
		printli(h->next, np);
	}
}
