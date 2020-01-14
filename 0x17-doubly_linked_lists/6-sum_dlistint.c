#include "lists.h"

/**
 * sum_dlistint - get sum of list
 * @head: head ptr
 * Return: sum of numbers in list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
