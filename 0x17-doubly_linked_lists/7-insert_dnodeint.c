#include "lists.h"

/**
 * add_dnodeint_after - insert a node in a list after an element
 * @h: ptr to node
 * @n: value of new node
 * Return: ptr to new node, or NULL if failed
 */
dlistint_t *add_dnodeint_after(dlistint_t *h, int n)
{
	dlistint_t *new;

	if (!h)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = h->next;
	new->prev = h;
	if (h->next)
		h->next->prev = new;
	h->next = new;
	return (new);
}


/**
 * insert_dnodeint_at_index - insert node at index in list (slow)
 * @h: head ptr
 * @idx: index
 * @n: number to insert
 * Return: ptr to new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *curr;

	if (!h)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));

	curr = *h;
	while (--idx)
		if (curr)
			curr = curr->next;
		else
			return (NULL);
	return (add_dnodeint_after(curr, n));
}

