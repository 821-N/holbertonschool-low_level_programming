#include "sort.h"
#include <stdio.h>

/**
 * push_back - swap a node with the previous node, and update head
 * assumes that node is not null and is not the first node in the list
 * @head: head
 * @node: node to swap backwards
 */
static void push_back(listint_t **head, listint_t *node)
{
	listint_t *prev = node->prev;

	prev->next = node->next;
	if (prev->prev)
		prev->prev->next = node;
	node->prev = prev->prev;
	prev->prev = node;
	if (node->next)
		node->next->prev = prev;
	node->next = prev;

	if (prev == *head)
		*head = node;
}

/**
 * find_place - move a node backwards until it's in the correct sorted position
 *  and print each step
 * @head: head
 * @node: node
 */
static void find_place(listint_t **head, listint_t *node)
{
	int n = node->n;

	while (node->prev && n < node->prev->n)
	{
		push_back(head, node);
		print_list(*head);
	}
}

/**
 * insertion_sort_list - sort a doubly linked list using insertion sort
 *  and print after each change
 * @list: address of head ptr
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *next;

	if (!list || !*list) /* NULL or empty list */
		return;

	curr = (*list)->next;
	while (curr)
	{
		next = curr->next;
		find_place(list, curr);
		curr = next;
	}
}
