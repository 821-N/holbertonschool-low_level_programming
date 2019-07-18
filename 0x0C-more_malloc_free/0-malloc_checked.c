#include <stdlib.h>

/**
 * malloc_checked - try to allocate memory, and exit(98) if fail
 *
 * @b: number of bytes
 * Return: pointer
 */
void *malloc_checked(unsigned int b)
{
	void *ret = malloc(b);

	if (!ret)
		exit(98);

	return ret;
}
