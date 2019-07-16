#include <stdlib.h>

/**
 * create_array - allocate/initialize a char array
 *
 * @size: size to allocate. Must be > 0
 * @c: char to fill with
 * Return: pointer to allocated array, or NULL
 */
char *create_array(unsigned int size, char c)
{
	char *ret;
	int i;

	if (size <= 0)
		return (NULL);
	ret = malloc(size);
	if (!ret)
		return (NULL);

	for (i = 0; i < size; i++)
		ret[i] = c;

	return (ret);
}
