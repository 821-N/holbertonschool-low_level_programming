#include <math.h>
#include <stdio.h>

/**
 * jump_search - search for value in sorted array using jump search
 * @array: array to search in (must be sorted)
 * @size: number of items in @array
 * @value: value to search for
 * Return: index, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, s = 0, blocksize = (size_t)sqrt((double)size);

	if (!size)
		return (-1);
	for (i = 0; i < size; i += blocksize)
	{
		if (array[i] >= value)
			break;
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		s = i;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", s, i);
	if (i >= size)
		i = size - 1;

	for (; s <= i; s++)
	{
		printf("Value checked array[%ld] = [%d]\n", s, array[s]);
		if (array[s] == value)
			return (s);
	}
	return (-1);
}
