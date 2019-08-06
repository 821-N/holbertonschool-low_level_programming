#include "lists.h"

/**
 * add_nodeint - add item to start of linked list
 *
 * @head: pointer to head pointer (will be modified)
 * @n: int to add
 * Return: pointer to new head, or NULL if failed
 */
listint_t *add_nodeint(listint_t **head, int n)
{
	listint_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;

	return (*head = new);
}
