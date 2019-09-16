#include "lists.h"

/**
 * delete_dnodeint_at_index - remove node from list (slow)
 * If head is deleted, NEXT node becomes new head.
 * @head: address of head ptr
 * @index: index of node to remove
 * Return: 1 (success) or -1 (failure)
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr;

	if (!head)
		return (-1);
	/* find node */
	curr = *head;
	while (--index)
		if (curr)
			curr = curr->next;
		else
			return (-1);
	if (!curr)
		return (-1);
	/* link prev/next */
	if (curr->prev)
		curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;
	/* free */
	if (curr == *head)
		*head = curr->next;
	free(curr);

	return (1);
}
