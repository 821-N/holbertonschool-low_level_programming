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
	char *new, *newer, *ptr2 = ptr;

	if (ptr2 == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr2);

	free(ptr2);
	/* allocate new array */
	if (new_size == 0)
		return (NULL);
	newer = new = malloc(new_size);
	if (!new)
		return (NULL);
	/* copy data to new array */
	if (old_size > new_size)
		old_size = new_size;
	while (old_size-- > 0)
		*newer++ = *ptr2++;

	return (new);
}
