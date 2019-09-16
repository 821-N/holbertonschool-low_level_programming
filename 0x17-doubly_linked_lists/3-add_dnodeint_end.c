#include "lists.h"

/**
 * add_dnodeint_end - add node to end of list (SLOW!)
 * @head: address of head pointer
 * @n: number to insert
 * Return: pointer to new node, or NULL if failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *curr;

	if (!head)
		return (NULL);
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = *head;
	new->n = n;

	if (!*head)
		return (*head = new);

	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	new->prev = curr;
	return (new);
}
