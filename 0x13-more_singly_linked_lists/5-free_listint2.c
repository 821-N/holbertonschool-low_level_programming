#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - free a linked list
 *
 * @head: first item in list
 */
void free_listint2(listint_t **head)
{
	listint_t *next;

	if (!head)
		return;

	while (*head)
	{
		next = (*head)->next;
		free(*head);
		(*head) = next;
	}
	*head = NULL;
}
