#include <stdio.h>

/**
 * interpolation_search - search in sorted array using interpolation search
 * @array: array to search in (must be sorted)
 * @size: number of items in @array
 * @value: value to search for
 * Return: index, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high, pos;

	if (!size || !array)
		return (-1);
	high = size - 1;

	while (array[high] != array[low] &&
	       array[low] <= value && array[high] >= value)
	{
		pos = low + (double)(high - low) / (array[high] - array[low]) *
			(value - array[low]);
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] < value)
			low = pos + 1;
		else if (array[pos] > value)
			high = pos - 1;
		else
			return (pos);
	}
	if (value == array[low])
		return (low);
	return (-1);
}
