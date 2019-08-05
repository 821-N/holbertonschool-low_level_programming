#include "lists.h"

/**
 * pop_listint - remove the first item and return its value
 * @head: address of pointer to first item
 * Return: value of removed item, or 0
 */
int pop_listint(listint_t **head)
{
	int ret;
	listint_t *next;

	if (!head || !*head)
		return (0);

	ret = (*head)->n;
	next = (*head)->next;
	free(*head);
	*head = next;
	return (ret);
}
