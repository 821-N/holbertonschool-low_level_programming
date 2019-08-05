#include "lists.h"
#include <stdio.h>

/**
 * listint_len - get length of linked list
 * @h: first item in list
 * Return: number of items in list
 */
size_t listint_len(const listint_t *h)
{
	if (!h)
		return (0);
	return (1 + listint_len(h->next));
}
