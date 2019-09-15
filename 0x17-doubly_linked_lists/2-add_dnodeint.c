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
	if (*head) /* ooh it lines up! if you have 3 space indent.. */
		(*head)->prev = new;
	else
		*head = new;
	return (new);
}
