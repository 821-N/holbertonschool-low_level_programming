#include <stdlib.h>

/**
 * array_range - generate array containing numbers @min to @max
 *
 * @min: first number
 * @max: last number (should be >= @min)
 * Return: pointer to array, or NULL
 */
int *array_range(int min, int max)
{
	unsigned int range;
	int *new, *newer;

	if (min > max)
		return (NULL);
	range = max - min + 1;
	newer = new = (void *)malloc(sizeof(int) * range);
	if (!new)
		return (NULL);
	for (; min <= max; min++)
		*newer++ = min;
	return (new);
}
