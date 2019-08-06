#include "lists.h"

/**
 * find_listint_loop - find a loop in a linked list
 *  Based on code from
 *  http://geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list
 * @head: pointer to first item in list
 * Return: a pointer to the start of the loop, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
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
	do {
		head = head->next;
		fast = fast->next;
	} while (head->next != fast->next);
	return (fast->next);
}
