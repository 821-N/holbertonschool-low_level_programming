#include <stdlib.h>

/**
 * _realloc - realloc!
 *
 * @ptr: pointer
 * @old_size: new size
 * @new_size: lol
 * Return: another pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new, *newer;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	/* allocate new array */
	if (new_size == 0)
		return (NULL);
	newer = new = malloc(new_size);
	if (!new)
		return (NULL);
	/* copy data to new array */
	if (old_size < new_size)
		old_size = new_size;
	while (old_size-- > 0)
		*newer++ = *(char *)ptr++;

	return (new);
}
