#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - print list
 * @h: list
 * Return: length of @h
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t length = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		length++;
	}
	return (length);
}
