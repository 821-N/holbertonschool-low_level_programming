#include "lists.h"
#include <stdio.h>

/**
 * find_loop - find a loop in a linked list
 * @head: pointer to start of list
 * Return: a pointer to the last unique item, or NULL if no loop exists
 */
listint_t *find_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (!head || !head->next) /* list has 0 or 1 items */
		return (NULL);

	do {
		slow = slow->next;
		fast = fast->next->next;
		if (!fast || !fast->next)
			return (NULL); /* found end of list */
	} while (slow != fast);
	/* found loop */
	while (head->next != fast->next)
	{
		head = head->next;
		fast = fast->next;
	}
	return (fast);
}

/**
 * free_listint_safe - free a linked list.
 * @h: address of pointer to first item
 * Return: size of list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *last, *next;
	size_t size = 0;

	if (!h)
		return (0);

	last = find_loop(*h);
	if (last)
		last->next = NULL;

	last = *h;
	while (last)
	{
		next = last->next;
		free(last);
		size += sizeof(listint_t);
		last = next;
	}

	*h = NULL;
	return (size);
}
