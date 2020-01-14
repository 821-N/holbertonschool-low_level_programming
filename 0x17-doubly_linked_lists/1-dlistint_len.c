#include "lists.h"

/**
 * dlistint_len - get length of list
 * @h: list
 * Return: length of @h
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t length = 0;

	while (h)
	{
		h = h->next;
		length++;
	}
	return (length);
}
