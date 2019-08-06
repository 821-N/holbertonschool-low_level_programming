#include "lists.h"
#include <stdio.h>

/**
 * last_item - find the last item in a linked list
 *  Based on code from
 *  http://geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list (method 3)
 *  except this one actually works!
 * @head: pointer to first item in list
 * Return: a pointer to the last item in the list
 */
listint_t *last_item(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	if (!head) /* empty list */
		return (NULL);
	do {
		if (!fast->next)
			return (fast);
		if (!fast->next->next)
			return (fast->next);
		if (slow->next == head)
			return (slow);
		slow = slow->next;
		fast = fast->next->next;
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

	if (!h || !*h)
		return (0);

	last = last_item(*h);

	while (1)
	{
		next = (*h)->next;
		size++;
		free(*h);
		if (*h == last)
			break;
		*h = next;
	}

	*h = NULL;
	return (size);
}
