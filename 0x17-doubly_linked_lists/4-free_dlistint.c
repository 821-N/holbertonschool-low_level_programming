#include "lists.h"

/**
 * free_dlistint - free list
 * @head: head ptr
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
