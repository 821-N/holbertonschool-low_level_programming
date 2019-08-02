#include "lists.h"
#include <stdlib.h>

/**
 * free_list - free a linked list and all strings inside
 *
 * @head: first item in list
 */
void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->str);
		free(head);
		head = next;
	}
}
