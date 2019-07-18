#include <stdlib.h>

/**
 * _calloc - allocate and 0-fill @size * @nmemb bytes of memory
 *
 * @nmemb: number of items (returns NULL if 0)
 * @size: size of each item (returns NULL if 0)
 * Return: pointer to allocated memory, or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *new;

	size *= nmemb;
	if (!size)
		return (NULL);

	new = malloc(size);
	if (!new)
		return (NULL);

	for (nmemb = 0; nmemb < size; nmemb++)
		new[nmemb] = 0;

	return (new);
}
