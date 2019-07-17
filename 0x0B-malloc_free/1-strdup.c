#include <stdlib.h>

/**
 * _strdup - create a copy of a string
 *
 * @str: string
 * Return: pointer to new string, or NULL
 */
char *_strdup(char *str)
{
	unsigned int length;
	char *new;

	/* check str */
	if (!str)
		return (NULL);
	for (length = 0; str[length]; length++)
		;
	/* allocate */
	new = malloc(length + 1);
	if (!new)
		return (NULL);
	/* copy */
	while (length--)
		new[length] = str[length];
	return (new);
}
