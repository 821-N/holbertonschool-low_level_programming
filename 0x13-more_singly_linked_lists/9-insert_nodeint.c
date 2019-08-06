#include "lists.h"

/**
 * insert_nodeint_at_index - insert node in linked list
 * @head: address of pointer to first item
 * @idx: position of new item
 * @n: value of new item
 * Return: pointer to new item
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *next, *prev = NULL;
	unsigned int i;

	if (!head)
		return (NULL);

	next = *head;
	for (i = 0; i < idx; i++)
	{
		if (!next)
			return (NULL);
		prev = next;
		next = next->next;
	}

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = next;

	if (prev)
		prev->next = new;
	else
		*head = new;

	return (new);
}
