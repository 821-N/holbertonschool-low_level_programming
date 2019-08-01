#include <string.h>
#include "lists.h"

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	char *str2;
	unsigned int length;

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
	new->next = *head;

	return (*head = new);
}
