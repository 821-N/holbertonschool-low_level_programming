#include "lists.h"

/**
 * delete_nodeint_at_index - delete a node in a linked list
 * @head: address of pointer to head
 * @index: position of node to delete
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *next, *prev;

	/* if invalid pointer passed, or list is empty */
	if (!head || !*head)
		return (-1);

	/* removing first item: head changes */
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}

	next = *head;
	while (index--)
	{
		if (!next) /* reached end of list */
			return (-1);
		prev = next;
		next = next->next;
	}
	prev->next = next->next;
	free(next);
	return (1);
}
