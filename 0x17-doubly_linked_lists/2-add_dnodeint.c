#include "lists.h"

/**
 * add_dnodeint - add node to start of list
 * @head: address of head pointer
 * @n: number to add
 * Return: pointer to new item or NULL if failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	if (!head)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->next = *head;
	new->n = n;
	if (!*head) /* if list is empty */
		*head = new;
	else /* not empty */
	{
		if ((*head)->prev) /* not actually at start of list! */
			(*head)->prev->next = new;
		(*head)->prev = new;
	}
	return (new);
}
