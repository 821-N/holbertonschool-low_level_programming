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

	while (array[high] != array[low])
	{
		pos = low + (double)(high - low) / (array[high] - array[low]) *
			(value - array[low]);
		if (pos >= size || pos < 0)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] < value)
			low = pos + 1;
		else if (array[pos] > value)
			high = pos - 1;
		else
			return (pos);
		if (array[low] > value || array[high] < value)
			return (-1);
	}
	if (value == array[low])
		return (low);
	return (-1);
}
