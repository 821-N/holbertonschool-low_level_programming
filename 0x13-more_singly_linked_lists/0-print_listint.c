#include "lists.h"
#include <stdio.h>

/**
 * print_listint - print a linked list of integers
 * @h: first item in list
 * Return: number of items in list
 */
size_t print_listint(const listint_t *h)
{
	if (!h)
		return (0);
	printf("%d\n", h->n);
	return (1 + print_listint(h->next));
}
