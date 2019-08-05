#include "lists.h"

/**
 * reverse_listint - reverse a linked list
 * @head: address of pointer to first item
 * Return: new head (also written to *@head)
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next;

	if (!head)
		return (NULL);

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	return (*head = prev);
}
