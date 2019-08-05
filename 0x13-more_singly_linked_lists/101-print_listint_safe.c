#include "lists.h"
#include <stdio.h>

/**
 * is_before - check if @first occurs before @second in @head
 * @head: pointer to start of list
 * @first: item which should be first
 * @second: item which should be second.
 * Return: if @first is before @second.
 *
 * This function is for finding cycles in linked lists.
 * @first->next should be @second.
 * If @first points to @second, @second must not also be in the
 * list before @first, otherwise a cycle exists.
 */
int is_before(
	const listint_t *head,
	const listint_t *first,
	const listint_t *second
)
{
	/* Optimization for when item points to itself */
	if (first == second)
		return (0);
	while (head)
	{
		/* Reached @second BEFORE @first, meaning that */
		/* it doesn't point to the earliest occurrence */
		if (head == second)
			return (0);
		/* Reached @first before @second, so @first */
		/* points to the first occurence of @second */
		if (head == first)
			return (1);
		head = head->next;
	}
	/* reached end of list without finding either item */
	/* something is wrong! */
	exit(98);
	return (0);
}

/**
 * print_listint_safe - print a linked list of integers
 * @h: first item in list
 * Return: number of items in list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *prev = NULL, *curr = head;
	size_t length = 0;

	while (curr)
	{
		if (prev && !is_before(head, prev, curr))
		{
			printf("-> [%p] %d\n", curr, curr->n);
			exit(98);
		}
		printf("[%p] %d\n", curr, curr->n);

		prev = curr;
		curr = curr->next;
		length++;
	}
	return (length);
}
