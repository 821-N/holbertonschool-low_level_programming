#include "lists.h"

/**
 * list_len - get the length of a linked list
 *
 * @h: linked list
 * Return: length
 */
size_t list_len(const list_t *h)
{
	if (!h)
		return (0);
	return (1 + list_len(h->next));
}
