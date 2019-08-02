#include <string.h>
#include "lists.h"

/**
 * add_node_end - add node to end of linked list (warning: slow!)
 *
 * @head: pointer to head struct pointer
 * @str: string to add
 * Return: pointer to new item, or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	char *str2;
	unsigned int length;
	list_t *end;

	if (!str || !head)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	for (length = 0; str[length]; length++)
		;

	str2 = strdup(str);
	if (!str2)
	{
		free(new);
		return (NULL);
	}

	new->str = str2;
	new->len = length;
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
