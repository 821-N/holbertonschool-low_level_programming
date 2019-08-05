#include "lists.h"

/**
 * add_nodeint_end - add node to end of linked list (warning: slow!)
 *
 * @head: pointer to head struct pointer
 * @n: int to add
 * Return: pointer to new item, or NULL if failed
 */
listint_t *add_nodeint_end(listint_t **head, int n)
{
	listint_t *new, *end;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));

	new->n = n;
	new->next = NULL;

	if (!*head)
		*head = new;
	else
	{
		end = *head;
		while (end->next)
			end = end->next;
		end->next = new;
	}
	return (new);
}
