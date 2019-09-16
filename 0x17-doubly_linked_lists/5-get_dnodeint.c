#include "lists.h"

/**
 * get_dnodeint_at_index - get node at index in list (slow)
 * @head: head ptr
 * @index: index
 * Return: ptr to node at index, or NULL if failed
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	while (index--)
		if (head)
			head = head->next;
		else
			return (NULL);
	return (head);
}
