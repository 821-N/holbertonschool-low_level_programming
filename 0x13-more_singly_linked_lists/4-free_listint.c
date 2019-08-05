#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - free a linked list
 *
 * @head: first item in list
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
