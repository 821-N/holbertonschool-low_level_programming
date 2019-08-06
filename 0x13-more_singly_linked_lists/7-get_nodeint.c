#include "lists.h"

/**
 * get_nodeint_at_index - get a node in a linked list
 * @head: pointer to first item
 * @index: index of item to get
 * Return: pointer to @index-th item, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	if (index == 0)
		return (head);
	if (head)
		return (get_nodeint_at_index(head->next, index - 1));
	return (NULL);
}
